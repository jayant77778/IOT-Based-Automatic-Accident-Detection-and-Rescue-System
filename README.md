

# IoT-Based Automatic Accident Detection and Rescue System

**Developed by [Jayant Bhati](https://github.com/jayant77778)**

This project focuses on building an **IoT-powered system** that can **automatically detect vehicular accidents** and **immediately alert emergency services and predefined contacts** with accurate location details — helping reduce response time and potentially saving lives.

---

## 📚 Table of Contents

* [Introduction](#introduction)
* [Key Features](#key-features)
* [Technologies Used](#technologies-used)
* [Hardware & Software Setup](#hardware--software-setup)
* [How It Works](#how-it-works)
* [System Architecture](#system-architecture)
* [Project Structure](#project-structure)
* [Contributing](#contributing)
* [License](#license)
* [Contact](#contact)

---

## 📝 Introduction

Road accidents are one of the leading causes of fatalities worldwide, and **delayed emergency response** often increases the severity of the situation. To address this issue, I developed an **IoT-based automatic accident detection and rescue system** that can:

* Detect accidents in real-time.
* Automatically send alerts to emergency contacts.
* Share the exact GPS location of the accident.

This project aims to bridge the gap between **accident detection** and **emergency response**, ultimately aiming to **save lives** through rapid intervention.

---

## 🚀 Key Features

* **Accident Detection**
  Detects collisions using accelerometers and vibration sensors.

* **Automatic Alert System**
  Instantly sends SMS alerts to registered contacts and emergency services.

* **Real-Time Monitoring**
  Constantly monitors the vehicle’s motion and condition.

* **Location Tracking**
  Integrates GPS to accurately pinpoint the accident location.

---

## 🛠️ Technologies Used

* **Microcontroller:** Arduino
* **Location Module:** GPS Module
* **Communication:** GSM Module (SIM-based SMS alert system)
* **Sensors:** MPU-6050 (Accelerometer/Gyroscope), Vibration Sensor
* **IoT Platform:** MQTT / ThingsBoard (Optional for expansion)
* **Programming:** C/C++ (Arduino IDE), Python (for backend integration if needed)

---

## ⚙️ Hardware & Software Setup

### 🔌 Hardware Setup

1. Connect the following components:

   * Arduino Uno
   * GPS Module (e.g., NEO-6M)
   * GSM Module (e.g., SIM800L)
   * MPU-6050 Accelerometer/Gyroscope
   * Vibration Sensor
2. Power the system via battery or USB.
3. Refer to the circuit diagram in the `Diagrams/` folder.

### 💻 Software Setup

1. **Clone the repository:**

   ```bash
   git clone https://github.com/jayant77778/IoT-Based-Automatic-Accident-Detection-And-Rescue-system.git
   ```

2. **Install Arduino Libraries:**

   * `TinyGPS++`
   * `SoftwareSerial`
   * `Wire`
   * `MPU6050`

3. **Upload Code:**

   * Open the `.ino` file using Arduino IDE.
   * Set the correct COM port and board (e.g., Arduino Uno).
   * Upload the code.

4. **Configure GSM Settings:**

   * Insert SIM card into the GSM module.
   * In the Arduino code, update the phone numbers of emergency contacts.

---

## 🔄 How It Works

1. The sensors constantly monitor motion and vibrations.
2. On detecting a potential accident (e.g., sudden deceleration or impact), the system:

   * Gathers location via GPS.
   * Sends an alert SMS to emergency contacts through GSM.
3. Optional: Sends data to an IoT dashboard for remote monitoring (e.g., via MQTT).

---

## 🧱 System Architecture

```
+------------------------+
|  Sensors (MPU6050,     |
|  Vibration Sensor)     |
+-----------+------------+
            |
            v
+------------------------+
|     Arduino Board      |
+-----------+------------+
            |
     +------+------+
     |             |
     v             v
+--------+     +--------+
|  GPS   |     |  GSM   |
| Module |     | Module |
+--------+     +--------+
     |             |
     +-------------+
            |
            v
+----------------------------+
| Emergency Contact Alerting |
| (SMS with Location Data)   |
+----------------------------+
```

---

## 📁 Project Structure

```
IoT-Based-Automatic-Accident-Detection-And-Rescue-system/
│
├── Arduino/                # Arduino source code (.ino files)
├── Diagrams/               # Circuit diagrams and architecture
├── README.md               # Documentation
└── LICENSE                 # MIT License
```

---

## 🤝 Contributing

Contributions are welcome! Here's how to contribute:

1. Fork this repository.
2. Create your feature branch:
   `git checkout -b feature/your-feature-name`
3. Commit your changes:
   `git commit -m "Add some feature"`
4. Push to the branch:
   `git push origin feature/your-feature-name`
5. Create a Pull Request.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 📬 Contact

Have questions, suggestions, or feedback? Feel free to reach out:

* **GitHub:** [Jayant Bhati](https://github.com/jayant77778)
* **Email:** jai77bhati@gmail.com


