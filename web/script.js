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
            const plotImg = document.getElementById('plot');
            plotImg.src = data.plot; // Directly assign the base64 string to the src attribute
            plotImg.style.display = 'block'; // Ensure the image is displayed
        })
        .catch((error) => {
            console.error('Error:', error);
        });
});

particlesJS.load('particles-js', 'particles.json', function() {
    console.log('particles.js config loaded');
});