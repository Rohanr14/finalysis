document.getElementById('analyze-form').addEventListener('submit', function (event) {
    event.preventDefault();
    const symbol = document.getElementById('symbol').value;
    const applySentiment = document.getElementById('sentiment-toggle').checked;

    fetch('/analyze', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ symbol: symbol, applySentiment: applySentiment }),
    })
        .then(response => response.json())
        .then(data => {
            document.getElementById('risk-score').innerText = `Risk Score: ${data.risk}`;
            const plotData = data.data.map((y, i) => ({ x: i, y }));

            const trace = {
                x: plotData.map(p => p.x),
                y: plotData.map(p => p.y),
                type: 'scatter'
            };

            const layout = {
                title: 'Stock Price Over Time',
                xaxis: {
                    title: 'Time'
                },
                yaxis: {
                    title: 'Stock Price'
                }
            };

            Plotly.newPlot('plot', [trace], layout);
        })
        .catch((error) => {
            console.error('Error:', error);
        });
});

particlesJS.load('particles-js', 'particles.json', function() {
    console.log('particles.js config loaded');
});