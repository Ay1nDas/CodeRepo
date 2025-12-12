let score = JSON.parse(localStorage.getItem('score'));

if (!score) {
  score = {
    total: 0,
    wins: 0,
    losses: 0,
    ties: 0,
  };
}

function playGame(choice) {
  score.total++;
  const compChoice = compPlay();

  displayCompChoice(compChoice);
  displayPlayerChoice(choice);

  if (choice === compChoice) {
    tie();
    score.ties++;
  } else if (choice === 'rock' && compChoice === 'scissors') {
    win();
    score.wins++;
  } else if (choice === 'paper' && compChoice === 'rock') {
    win();
    score.wins++;
  } else if (choice === 'scissors' && compChoice === 'paper') {
    win();
    score.wins++;
  } else {
    lose();
    score.losses++;
  }
  updateScore();

  localStorage.setItem('score', JSON.stringify(score));
}

function compPlay() {
  const rand = Math.random();
  if (rand < 0.34) {
    return 'rock';
  } else if (rand <= 0.67) {
    return 'paper';
  } else {
    return 'scissors';
  }
}

function win() {
  const verdict = document.querySelector('.js-verdict');

  verdict.innerHTML = 'You Win!';

  verdict.classList.remove('tie');
  verdict.classList.remove('lose');
  verdict.classList.add('win');
}

function lose() {
  const verdict = document.querySelector('.js-verdict');

  verdict.innerHTML = 'You Lose!';

  verdict.classList.remove('win');
  verdict.classList.remove('tie');
  verdict.classList.add('lose');
}

function tie() {
  const verdict = document.querySelector('.js-verdict');

  verdict.innerHTML = "It's a Tie!";

  verdict.classList.remove('lose');
  verdict.classList.remove('win');
  verdict.classList.add('tie');
}

function displayCompChoice(compChoice) {
  const compMove = document.querySelector('.js-comp-move');

  if (compChoice === 'rock') {
    compMove.innerHTML = '✊';
  } else if (compChoice === 'paper') {
    compMove.innerHTML = '✋';
  } else {
    compMove.innerHTML = '✌️';
  }
}

function displayPlayerChoice(choice) {
  if (choice === 'rock') {
    document.querySelector('.js-player-move').innerHTML = '✊';
  } else if (choice === 'paper') {
    document.querySelector('.js-player-move').innerHTML = '✋';
  } else {
    document.querySelector('.js-player-move').innerHTML = '✌️';
  }
}

function updateScore() {
  document.querySelector('.js-total').innerText = score.total;
  document.querySelector('.js-win').innerText = score.wins;
  document.querySelector('.js-lose').innerText = score.losses;
  document.querySelector('.js-tie').innerText = score.ties;
}

function resetScore() {
  score = {
    total: 0,
    wins: 0,
    losses: 0,
    ties: 0,
  };
  updateScore();
  localStorage.removeItem('score', JSON.stringify(score));
}

updateScore();
