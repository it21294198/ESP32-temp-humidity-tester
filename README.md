1. Created 2 folders `server` for backend and `IoT-esp32` for data collection device.

2. On `server` folder node server setup was initialized with following commands.
    ```
    npm init -y
    ```
    ```
    npm install express body-parser cors
    ```
    This is used to extract IP address on localhost device for ESP32.(This may changed time to time)
    ```
    npm install ip
    ```
3. Create `index.js` on root folder and run it.
    ```
    node index.js
    ```
4. Follow ESP32 setup with this [Click Here](https://youtu.be/14LhUS1osYg?si=52WouakKIHm-y0Br)

5. System view
   ![System view](./Test/esp32-wifi-server.png)
