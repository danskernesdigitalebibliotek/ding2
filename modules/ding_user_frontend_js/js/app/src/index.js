import React from 'react';
import ReactDOM from 'react-dom';
import UserDashboard from './components/Dashboard/UserDashboard';
import './css/UserDashboard.css';

const root = document.getElementById('ding-user-frontend-js-user-dashboard');
ReactDOM.render(<UserDashboard token={root.dataset.apiToken} />, root);
