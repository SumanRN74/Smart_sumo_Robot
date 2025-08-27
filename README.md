# 🤖 Smart sumo Robot

This project presents a **Robo Sumo Bot** built using an **Arduino Uno**, **L298N Motor Driver**, and an **Ultrasonic Sensor**.The bot is programmed to **detect opponents within a range of 50 cm** and actively **push them out of the ring**.

In the absence of an opponent, the bot employs a **search strategy** — it **rotates to the right**, **moves forward slightly**, and then **resumes scanning**.This cycle continues until an opponent is detected, ensuring **continuous engagement** during the match. 

The design emphasizes **autonomous decision-making**, **efficient movement**, and **competitive performance** in robotic sumo contests.

---

## 🏆 Achievement
This project was successfully demonstrated at **Robofiesta 2024** (R V Institute of Technology and Management),  
where it competed in the **Robo Sumo Main Event** and secured **3rd Place** 🎉

The participation/completion certificate for this project is attached in the same repository named as "certificate.png".

---

## 🔧 Components Used
- 1 × Arduino Uno  
- 1 × L298N Motor Driver Module  
- 4 × DC Geared Motors  
- 1 × Ultrasonic Sensor HC-SR04  
- 1 × LED (Power Indicator)  
- 1 × Battery Pack (6V–12V, depending on motor requirement)  
- Jumper Wires & Breadboard (if required)  
- Chassis for Robo Sumo Bot  

---

## ⚡ Pin Connections
| Component             | Arduino Pin | Notes |
|------------------------|-------------|-------|
| L298N ENA             | D9          | Left Motor Speed (PWM) |
| L298N IN1             | D8          | Left Motor Direction 1 |
| L298N IN2             | D7          | Left Motor Direction 2 |
| L298N ENB             | D10         | Right Motor Speed (PWM) |
| L298N IN3             | D6          | Right Motor Direction 1 |
| L298N IN4             | D5          | Right Motor Direction 2 |
| Ultrasonic TRIG       | D3          | Trigger Pin |
| Ultrasonic ECHO       | D2          | Echo Pin |
| LED (Power Indicator) | D13         | ON when bot is powered |
| Battery VCC (+)       | L298N +12V  | Motor Power |
| Battery GND (–)       | Arduino GND + L298N GND (Common Ground) |

📷 **Schematic Reference:**  
Attached in the repository named "schematic.jpg"

---

## 🛠️ Working Principle
1. **Ultrasonic sensor** continuously measures distance.  
2. If opponent is detected within **50 cm → Bot drives forward** at full speed to push it out.  
3. If no opponent is detected → Bot **rotates right slightly and moves forward ~5cm**, then scans again.  
4. This loop continues until the opponent is pushed outside the boundary.  

---

## 📜 Procedure to Implement
1. Assemble the chassis and mount **DC motors**.  
2. Connect motors to the **L298N motor driver**.  
3. Connect the **L298N** to **Arduino Uno** (as per pin connections).  
4. Wire the **HC-SR04 ultrasonic sensor** to detect opponents.  
5. Upload the Arduino code (`RoboSumo.ino`) provided in this repository.  
6. Power the bot using a **battery pack (6V–12V)**.  
7. Place the bot inside the ring → it will automatically start scanning and pushing the opponent.  

---

## ⚠️ Precautions
1. Do not power the **Ultrasonic Sensor (HC-SR04)** with more than **5V**.  
2. Ensure **common ground** between Arduino, L298N, and battery.  
3. Use a **battery holder** to prevent loose connections.  
4. Motors can draw high current → never power motors directly from Arduino 5V.  
5. If motors don’t spin → check **L298N jumpers** and wiring.  

---

## 👨‍💻 Author
**Suman R N**  
📧 Contact: sumansurn@gmail.com 
---
