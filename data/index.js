// index.js

function showGraphs() {
    var dashboard = document.getElementById('dashboard');
    var graphs = document.getElementById('graphs');
    dashboard.style.display = 'none';
    graphs.style.display = 'block';
}

function showDashboard() {
    var dashboard = document.getElementById('dashboard');
    var graphs = document.getElementById('graphs');
    dashboard.style.display = 'block';
    graphs.style.display = 'none';
}

// Function to make HTTP GET request and update data
function fetchDataAndUpdate() {
    fetch('/data')
        .then(response => response.json())
        .then(data => {
            // Update HTML elements with received data
            document.getElementById('temperature').innerText = data.temperature;
            document.getElementById('humidity').innerText = data.humidity;
            document.getElementById('moisture').innerText = data.moisture;
            document.getElementById('waterLevel').innerText = data.waterLevel;
            document.getElementById('waterValue').innerText = data.waterValue;
        })
        .catch(error => console.error('Error fetching data:', error));
}

fetchDataAndUpdate();

setInterval(fetchDataAndUpdate, 500);
