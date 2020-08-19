#!/usr/bin/node
const request = require('request');

function requesito (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) reject(error);
      resolve(body);
    });
  });
}

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], async function (error, response, body) {
  const characters = JSON.parse(body).characters;
  if (error !== null) {
    console.error(error);
  }
  let x = 0;
  while (x < characters.length) {
    try {
      const body = await requesito(characters[x]);
      console.log(JSON.parse(body).name);
    } catch (error) {
      console.error(error);
    }

    x = x + 1;
  }
});
