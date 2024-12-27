function checkAnswer(button, correctness) {
    const feedback = button.parentElement.querySelector('.feedback');
    if (correctness === 'correct') {
        button.style.backgroundColor = 'green';
        feedback.textContent = 'Correto!';
        feedback.className = 'feedback correct';
    } else {
        button.style.backgroundColor = 'red';
        feedback.textContent = 'Incorreto';
        feedback.className = 'feedback incorrect';
    }
}

function checkTextAnswer(inputId, feedbackId, correctAnswer) {
    const input = document.getElementById(inputId);
    const feedback = document.getElementById(feedbackId);
    if (input.value.trim() === correctAnswer) {
        input.style.backgroundColor = 'green';
        feedback.textContent = 'Correto!';
        feedback.className = 'feedback correct';
    } else {
        input.style.backgroundColor = 'red';
        feedback.textContent = 'Incorreto';
        feedback.className = 'feedback incorrect';
    }
}
