/*globals Cookies */
/**
 * @file
 * Implementation of the facet browser front-end to make the facet collapsible.
 */

(function($) {
  "use strict";

  /**
   * Fold facet groups to show only x unselected checkboxes per group.
   */
  function ding_facetbrowser_fold_facet_group(context) {
    // Select the facet browser HTML element.
    var facet_browser = $(Drupal.settings.ding_facetbrowser.selector, context);

    // Add show more button to each facet group and hide some terms.
    facet_browser.find('fieldset.form-wrapper').once('ding-facetbrowser-group', function() {
      var facetGroup = $(this);

      // Limit the number of visible terms in the group.
      var number_of_terms = Drupal.settings.ding_facetbrowser.number_of_terms;
      var terms_not_checked = facetGroup.find('.form-type-checkbox input:not(:checked)');
      if (terms_not_checked.length > number_of_terms) {
        terms_not_checked.slice(number_of_terms).parent().hide();
      }

      // Add expand button, if there are more to show.
      if (terms_not_checked.length > number_of_terms) {
        facetGroup.append('<a href="javascript:void;" class="expand expand-more">' + Drupal.t('Show more') + '</a>');
      }

      // Add classes to checkbox wrappers used to handle visibility.
      facetGroup.find('.form-type-checkbox input:checked').parent().addClass('selected-checkbox');
      facetGroup.find('.form-type-checkbox input:not(:checked)').parent().addClass('unselected-checkbox');

      // Add div wrappers around selected and unselected checkboxes to handle visibility.
      facetGroup.find('.selected-checkbox').wrapAll('<div class="selected-checkbox-group" />');
      facetGroup.find('.unselected-checkbox').wrapAll('<div class="unselected-checkbox-group" />');

      // Add a unselect all link.
      if (facetGroup.find('.selected-checkbox-group').length) {
        facetGroup.find('.selected-checkbox-group').append('<a href="#" class="unselect">' + Drupal.t('Remove all selected') + '</a>');
      }

    });

    /**
     * Bind click function to show more and show less links.
     */
    facet_browser.on('click', '.expand', function(e) {
      e.preventDefault();

      var clickedKey = $(this);
      var facetGroup = $(clickedKey).parent();

      facetGroup.find('.form-type-checkbox.unselected-checkbox:' + (clickedKey.hasClass('expand-more') ? 'hidden' : 'visible')).each(function(count, facetElement) {
        if (clickedKey.hasClass('expand-more') && count < Drupal.settings.ding_facetbrowser.number_of_terms) {
          $(facetElement).slideDown('fast', function() {
            if (facetGroup.find('.form-type-checkbox.unselected-checkbox:visible').length >= Drupal.settings.ding_facetbrowser.number_of_terms &&
                facetGroup.find('.expand-less').length === 0 &&
                count % Drupal.settings.ding_facetbrowser.number_of_terms === 0) {
              facetGroup.append('<a href="javascript:void;" class="expand expand-less">' + Drupal.t('Show less') + '</a>');
            }
          });
        }
        else if (clickedKey.hasClass('expand-less') && count >= Drupal.settings.ding_facetbrowser.number_of_terms) {
          $(facetElement).slideUp('fast', function() {
            if (facetGroup.find('.form-type-checkbox.unselected-checkbox:visible').length === parseInt(Drupal.settings.ding_facetbrowser.number_of_terms, 10) &&
                facetGroup.find('.expand-less:visible')) {
              facetGroup.find('.expand-less').fadeOut().remove();
            }
          });
        }
      });

      // Need to make sure we have the correct amount of unselected checkboxes to check against when wanting to remove the show more link.
      var unselectedSize = facetGroup.attr('count') - facetGroup.find('.form-type-checkbox.selected-checkbox').length;

      if ((facetGroup.find('.form-type-checkbox.unselected-checkbox:visible').length >= unselectedSize) && (clickedKey.hasClass('expand-more'))) {
        facetGroup.find('.expand-more').remove();
      }

      if (clickedKey.hasClass('expand-less')) {
        if (!(facetGroup.find('.expand-more').length)) {
          facetGroup.append('<a href="javascript:void;" class="expand expand-more">' + Drupal.t('Show more') + '</a>');
        }
      }

      return false;
    });

    /**
     * Bind click function to the un-select all selected checkboxes link.
     */
    facet_browser.find('.unselect').on('click', function(e) {
      e.preventDefault();

      var clickedKey = this;
      var facetGroup = $(clickedKey).parent();
      var checkedFacets = '';
      facetGroup.find('.form-type-checkbox.selected-checkbox').each(function() {
        var element = $(this);
        // Un-check checkboxes (for the visual effect).
        element.find('input').click();

        // Find the facets to be deselected and generate new URL.
        var facetMatch = element.find('a').attr('href').match(/&facets%5B%5D=-facet.*/);
        checkedFacets += facetMatch[0];
        if (checkedFacets) {
          Drupal.TingSearchOverlay();
          window.location.href += checkedFacets;
        }
      });

      return false;
    });
  }

  Drupal.behaviors.ding_facetbrowser = {
    attach: function(context) {
      // Fold facet groups as default.
      ding_facetbrowser_fold_facet_group(context);

      // Select the facet browser(s) HTML element.
      var facet_browsers = $(Drupal.settings.ding_facetbrowser.selector);

      // Hide extra facet groups (groups that have js-hidden class).
      facet_browsers.once('ding-facetbrowser', function(index, facet_browser) {
        // Create show more link.
        var show_more_groups = $('<a />', {
          href: '#',
          text:  Drupal.t('Show more filters'),
          class: 'expand expand-more'
        });

        // Create facet group wrapper.
        var wrapper = $('<div />', {
          class: 'hidden-facets-group'
        });

        // Add the wrapper and link to the browser.
        var browser = $(facet_browser);
        browser.find('.js-hidden').wrapAll(wrapper);
        wrapper = browser.find('.hidden-facets-group');
        wrapper.after(show_more_groups);

        // Add event handler to show more links.
        show_more_groups.click(function(e) {
          e.preventDefault();

          // Get the link clicked.
          var self = $(this);

          // Toggle facets groups and update link/button text.
          wrapper.toggle('fast', function () {
            var cookie = 0;
            if (self.hasClass('expand-more')) {
              show_more_groups.text(Drupal.t('Show less filters'));
              show_more_groups.removeClass('expand-more').addClass('expand-less');
              cookie = 1;
            }
            else {
              show_more_groups.text(Drupal.t('Show more filters'));
              show_more_groups.removeClass('expand-less').addClass('expand-more');
            }

            // Set cookie, so to remember if they where shown.
            Cookies.set('ding_facetbrowers_groups_shown', cookie);
          });

          return false;
        });

        // Check the cookie, if facet groups should be hidden or shown as default.
        if (parseInt(Cookies.get('ding_facetbrowers_groups_shown'), 10) === 1) {
          show_more_groups.trigger('click');
        }
      });

      // Check for click in checkbox, and execute search.
      facet_browsers.find('.form-type-checkbox input').change(function(e) {
        Drupal.TingSearchOverlay();
        window.location = $(e.target).parent().find('a').attr('href');
      });

      // Check facet links for click events.
      facet_browsers.find('.form-type-checkbox a').click(function() {
        if ($(this).not('[target="_blank"]').length) {
          Drupal.TingSearchOverlay();
        }
      });

      facet_browsers.find('.js-ding-facetbrowser-interval').not('.js-ding-facetbrowser-interval-processed').each(function () {
        var
          $this = $(this),
          facet_name = $this.attr('data-facet-name'),
          interval_settings = Drupal.settings.ding_facetbrowser.intervals[facet_name],
          $element = $this.addClass('js-ding-facetbrowser-interval-processed'),
          update_info = function (values) {
            $element.find('.ding-facetbrowser-interval__start').text(interval_settings.interval[values[0]]);
            $element.find('.ding-facetbrowser-interval__end').text(interval_settings.interval[values[1]]);
          };

        $element.find('.ding-facetbrowser-interval__slider').slider({
          range: true,
          min: 0,
          max: interval_settings.interval.length - 1,
          values: interval_settings.range,
          slide: function (evt, ui) {
            update_info(ui.values);
          },
          change: function (evt, ui) {
            var
              append = interval_settings.uri.indexOf('?') === -1 ? '?' : '&',
              url = interval_settings.uri + append,
              range = [
                parseInt(interval_settings.range[0], 10),
                parseInt(interval_settings.range[1], 10)
              ],
              url_replace_regex;

            // Don't refresh the page, if the values did not change.
            if (range[0] === ui.values[0] && range[1] === ui.values[1]) {
              return;
            }

            // Remove previous interval filters from the URL.
            url_replace_regex = new RegExp('facets\\[\\d*\\]=' + facet_name.replace(/\./g, '\\$&') + '[^&]+&?', 'g');
            url = url.replace(url_replace_regex, '');

            // Add new interval filters.
            url += 'facets[]=' + encodeURIComponent(facet_name + ':' + interval_settings.interval[ui.values[0]] + ':>=');
            url += '&facets[]=' + encodeURIComponent(facet_name + ':' + interval_settings.interval[ui.values[1]] + ':<=');

            Drupal.TingSearchOverlay();
            window.location = url;
          },
          create: function () {
            update_info(interval_settings.range);
          }
        });
      });
    }
  };

})(jQuery);
