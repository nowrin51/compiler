document.getElementById('parserForm').addEventListener('submit', function(event) {
    event.preventDefault();

    const formData = new FormData(this);

    fetch('parser.php', {
        method: 'POST',
        body: formData
    })
    .then(response => response.text())
    .then(data => {
        document.getElementById('outputContainer').innerHTML = data;
    })
    .catch(error => console.error('Error:', error));
});