const express = require("express");
const bodyParser = require("body-parser");
const cors = require("cors");
const ip = require("ip");

const localIP = ip.address();
const app = express();
const PORT = 3000;

app.use(cors());
app.use(bodyParser.json());

app.get("/", (req, res) => {
  res.status(200).send("Server is Running");
});

app.post("/data", (req, res) => {
  const { temperature, humidity } = req.body;

  if (temperature !== undefined && humidity !== undefined) {
    console.log(`Temperature: ${temperature}°C | Humidity: ${humidity}%`);
    res.status(200).send("Data received");
  } else {
    res.status(400).send("Invalid data");
  }
});

app.listen(PORT, () => {
  console.log(
    `Open this link to test ; server running on http://${localIP}:${PORT}`
  );
});
