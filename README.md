<!--
*** Thanks for checking out this README Template. If you have a suggestion that would
*** make this better, please fork the repo and create a pull request or simply open
*** an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
***
***
***
*** To avoid retyping too much info. Do a search and replace for the following:
***  PRGeeesus, Solo12-Robot, twitter_handle, email
-->





<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
<!--
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

-->

<!-- PROJECT LOGO -->
<br />
<p align="center">
  
  <h3 align="center">Solo12-Robot</h3>

  <p align="center">
    This repo summarizes my changes to the Open Dynamics Robot Initiative Project.
    <br />
    <a href="https://github.com/ai-lab-science/Solo12-Robot"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/ai-lab-science/Solo12-Robot">View Demo</a>
    ·
    <a href="https://github.com/ai-lab-science/Solo12-Robot/issues">Report Bug</a>
    ·
    <a href="https://github.com/ai-lab-science/Solo12-Robot">Request Feature</a>
  </p>
</p>


<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Useful Links](#Useful-Links)
* [Changes Made to Original](#All-changes-Made-to-Original)
  * [Magnetic Encoder](#Magnetic-Encoder)
  * [M3 Belts and Pulleys](#M3-Belts-and-Pulleys)
  * [Motor and Center Pulley](#Motor-and-Center-Pulley)
  * [20x20 Hip AA Bearings](#20x20-Hip-AA-Bearings)
  * [Foot Contact Switch](#Foot-Contact-Switch)

* [Supplier Links](#Supplier-Links)
* [License](#license)
* [Contact](#contact)
* [Acknowledgements](#acknowledgements)



<!-- ABOUT THE PROJECT -->
## About The Project

TODO:



#### Useful Links

* [Original Project by the Open Dynamic Robot Initiative](https://github.com/open-dynamic-robot-initiative/open_robot_actuator_hardware)

* [To-Dos for this Project]("https://github.com/ai-lab-science/Solo12-Robot/issues")


---
<!-- All changes Made to Original -->
## All changes made to the original

Here you can find the Documentation of all changes that were made to the original Robot.

---
### Magnetic Encoder

The original Robot uses an optical Encoder. Due to its cost and the effort in assembly this was replaced with a magbetic enoder by AMS called [AS5047](https://ams.com/AS5047P).

| Encoder Changes Mechanical | Encoder Changes Electrical | Config. and Arduino | uDriver |
|-------------|-------------|-------------|-------------|
|<a href="Magnetic-Encoder/README.md#Mechanical-changes"><img src="Magnetic-Encoder/images/new_encoder_cad.png" width="200"></a> | <a href="Magnetic-Encoder/README.md#Electrical-changes"><img src="Magnetic-Encoder/images/enocder_electronics.png" width="200"></a> | <a href="Magnetic-Encoder/README.md#Communication-Via-Arduino"><img src="Magnetic-Encoder/images/config_icon.png" width="200"></a>|<a href="uDriver-Firmware/README.md"><img src="Magnetic-Encoder/images/config_icon.png" width="200"></a>|



<!-- M3 Belts and Pulleys -->
---
### M3 Belts and Pulleys
The original Pulleys and Belts were repalced with M3 Pulleys and the fitting Belts.

* The new Belts were bought [here](https://www.zahnriemen24.de/a/40007-zahnriemen-3m)
* The new Pulleys were bought [here](https://www.zahnriemen24.de/a/40139-zahnscheiben-3m?vorbohrungspannsatz=1&bohrung=1&zaehnezahl=10&quantity=1)


The .STL files of the Pulleys were also updated:
|center pulley|Output Pulley|
|---|---|
|<img src="Parts_for_3D_printing\New-Pulleys\center_pulley_3DPrint_image.png" width="200">|<img src="Parts_for_3D_printing\New-Pulleys\output_pulley_image.png" width="200">|
|[.stl New Center Pulley](Parts_for_3D_printing/New-Pulleys/pulley_center_30t.stl)|[.stl New Output Pulley](Parts_for_3D_printing/New-Pulleys/pulley_output_30t.stl)|


---
### Motor and Center Pulley
The Motor Pulley, Center Pulley and Motor Shaft were machined according to:
| |Motor Pulley|Center Pulley|Motor Shaft|
|---|---|---|---|
|Manufactured:|<img src="Parts_for_machining\images\Motor_pulley.jpg" width="200">|<img src="Parts_for_machining\images\Center_pulley.jpg" width="200">|<img src="Parts_for_machining\images\Motor_shaft.jpg" width="200">|
|Assembly|<img src="Parts_for_machining\images\motor_assembly.jpg" width="200" >|<img src="Parts_for_machining\images\center_pulley_assembly.jpeg" width="200">||
|Machining Instructions PDF:|<a href="\Parts_for_machining\new_motor_Pulley_Zeichnung_v2.pdf" target="_blank">Motor Pulley</a>|<a href="\Parts_for_machining\New_Center_Pulley_10_teeth_Zeichnung_v0.pdf" target="_blank">Center Pulley</a>|<a href="\Parts_for_machining\motor_antigravity_4004_custom_shaft_Zeichnung_v1.pdf" target="_blank">Motor shaft</a>


* Parts in a lathe until they matched the Drawings:

<br>
<img src="Parts_for_machining\images\machining_center_pulley.jpg" height="300" border="2">


---
### 20x20 Hip AA Bearings
 The "Hip AA Bearing" of size 25 x 20 x 4mm were replaced with bearings of 27 x 20 x 4mm because of availability. The [.stl](\Parts_for_3D_printing\hip_aa_fromt_cover_27.2mm_bearing.stl) files were updated accordingly. The bearings were bought [here](https://www.123kugellager.de/lager-R2520-2Z-ZEN).


---
### Foot Contact Switch

* no foot contact switch was added yet. However, the cables are fed through for future add-on.
[Link](Foot-Contact-Switch/README.md)



## Supplier Links
All other parts were bought as described. I divided the Project into 3 parts.
Here is a table for all parts from the Main Body:

| Part        | Description | Suppliers   |
|-------------|-------------|------------|
| Hip AA Bearing | Bearing to attach Hip FE to the body | [123kugellager.de](https://store-en.tmotor.com/goods.php?id=438)|
| Fasteners | All fasteners as described by the original  | [online-schrauben.de](https://online-schrauben.de/shop/) |
<br>
Here is a table for all parts for one 3 DoF Leg:<br><br>

| Part        | Description | Suppliers   |
|-------------|-------------|------------|
| T-Motor Antigravity 4004 300kV | Motor for the actuator | [T-Motor Store](https://www.123kugellager.de/lager-R2520-2Z-ZEN)|
| Fasteners | All fasteners as described by the original  | [online-schrauben.de](https://online-schrauben.de/shop/) |
| Timing Belt 4mm / length: 150mm / 50 teeth | new M3 Timing Belts  | [www.zahnriemen24.de](https://www.zahnriemen24.de/a/40007-zahnriemen-3m) |
| Timing Belt 6mm / length: 201mm / 67 teeth | new M3 Timing Belts  | [www.zahnriemen24.de](https://www.zahnriemen24.de/a/40007-zahnriemen-3m) |
|Bearing Output Shaft 32mm x 25mm x 4mm | bearing for each output | [ekugellager.de](https://www.ekugellager.de)|
|Bearing Motor Shaft and Center Shaft |8mm x 4mm x 2mm bearing | " |[ekugellager.de](https://www.ekugellager.de)|
|Bearing Timing Belt Tensioner| - | " |
|Motor Shaft| new shaft | [reidl.de](https://www.reidl.de/iso-8740-zylinderkerbstifte-mit-fase?q=stahlzylinder)
|Motor and Center Pulley| new M3 Pulleys| [www.zahnriemen24.de](https://www.zahnriemen24.de/a/40139-zahnscheiben-3m?vorbohrungspannsatz=1&bohrung=1&zaehnezahl=10&quantity=1)|



## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

martin.buchschuster@student.uni-luebeck.de

Project Link: [This-site](https://github.com/ai-lab-science/Solo12-Robot)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* [Ralf Bruder]()
* [Elmar Rueckert]()
* [Martin Buchschuster]()

