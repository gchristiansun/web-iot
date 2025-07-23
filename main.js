const endPoint = "http://192.168.171.137"


function getDapurLed() {
    fetch(endPoint + "/dapur", {
        method: "GET"
    }).then(response => response.text()).then(result => {
        if(result == "ON") {
            ledDapur.style.backgroundColor = "blue"
            ledDapur.innerText = "TURN OFF"
            dapurLedImg.src = "/img/led-on.png"
        } else {
            ledDapur.style.backgroundColor = "#579fff"
            ledDapur.innerText = "TURN ON"
            dapurLedImg.src = "/img/led-off.png"
        }
    })   
}

function getTamuLed() {
    fetch(endPoint + "/tamu", {
        method: "GET"
    }).then(response => response.text()).then(result => {
        if(result == "ON") {
            ledTamu.style.backgroundColor = "blue"
            ledTamu.innerText = "TURN OFF"
            tamuLedImg.src = "/img/led-on.png"
        } else {
            ledTamu.style.backgroundColor = "#579fff"
            ledTamu.innerText = "TURN ON"
            tamuLedImg.src = "/img/led-off.png"
        }
    })   
}

function getMakanLed() {
    fetch(endPoint + "/makan", {
        method: "GET"
    }).then(response => response.text()).then(result => {
        if(result == "ON") {
            ledMakan.style.backgroundColor = "blue"
            ledMakan.innerText = "TURN OFF"
            makanLedImg.src = "/img/led-on.png"
        } else {
            ledMakan.style.backgroundColor = "#579fff"
            ledMakan.innerText = "TURN ON"
            makanLedImg.src = "/img/led-off.png"
        }
    })   
}

function setDapurLed() {
    fetch(endPoint + "/dapur", {
        method: "POST"
    }).then(response => response.text()).then(() => getDapurLed());
}

function setTamuLed() {
    fetch(endPoint + "/tamu", {
        method: "POST"
    }).then(response => response.text()).then(() => getTamuLed());
}

function setMakanLed() {
    fetch(endPoint + "/makan", {
        method: "POST"
    }).then(response => response.text()).then(() => getMakanLed());
}

function setToiletLed() {
}

getDapurLed();
getTamuLed();
getMakanLed();