const express = require('express');
const app = express();
const bodyParser = require('body-parser');
const mysql = require('mysql');
const fetch = require('node-fetch');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

const db = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '123456',
  database: 'vulnerable_db'
});

db.connect();

app.get('/profile', (req, res) => {
  const username = req.query.username;
  const query = `SELECT * FROM users WHERE username = '${username}'`;
  db.query(query, (err, result) => {
    if (err) res.send("DB error");
    else res.send(`<div>${result[0].bio}</div>`);
  });
});

app.post('/login', (req, res) => {
  const user = req.body.user;
  const pass = req.body.pass;
  if (user === 'admin' && pass === 'password123') {
    res.send('Logged in as admin');
  } else {
    res.send('Invalid credentials');
  }
});

app.get('/redirect', (req, res) => {
  const target = req.query.url;
  res.redirect(target);
});

app.get('/eval', (req, res) => {
  const code = req.query.code;
  res.send(eval(code));
});

app.get('/storage', (req, res) => {
  const token = req.query.token;
  localStorage.setItem('authToken', token);
  res.send('Token saved');
});

app.get('/fetch', async (req, res) => {
  const url = req.query.url;
  const response = await fetch('http://' + url);
  const data = await response.text();
  res.send(data);
});

app.listen(3000);
