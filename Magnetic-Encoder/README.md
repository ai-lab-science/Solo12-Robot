## Encoder Adaptation

The Optical encoder, enocder wheel and mount were replaces woth a magentic encoder.
For this, the AS5047 is mounted facing the end of the of shaft, to which a magnet is attached.
The Covers were modified to accept the footprint of the PCB.
<br><img src="images\encoder_board_explosionszeichnung.png" style="border:3px solid black;" height="400"><br>


## Mechanical Changes

All the covers of the leg modules were equipped with a recess of 3mm debth to hold the encoder board. The Motor-shaft was shortened by 3mm aswell. At the end of the shaft now sits a magnet that gives the rotational inofrmation to the AS5074.
Three holes for mounting as well as spacers are also given.


---
### Magnet for the Encoder
<img src="images\image_magnet_4mm.jpg" style="border:3px solid black;" height="200"><br>
* [Magnets Bought from here](https://www.magnetkontor.de)<br>


---
### New Shell Covers

* The list of STL files for 3d printing the new shells can be found here: [STL files 3dof leg](stl_files).

|Hip AA| Hip FE| Upper LEG|
|-------------|-------------|-------------|
|<img src="../Parts_for_3D_printing/New-Shell-Covers/images/new_hip_aa.png"  height="200">|<img src="../Parts_for_3D_printing/New-Shell-Covers/images/new_hip_fe.png" height="200">|<img src="../Parts_for_3D_printing/New-Shell-Covers/images/new_upper_leg.png" height="200">
|[Hip AA Module New Shell Cover - STL file](../Parts_for_3D_printing/New-Shell-Covers/cover_hip_aa.STL)|[Hip FE Module New Shell Cover - STL file](../Parts_for_3D_printing/New-Shell-Covers/cover_hip_fe.STL)|[Upper Leg Module New Shell Cover - STL file](../Parts_for_3D_printing/New-Shell-Covers/cover_upper_leg.STL)

<br><br>

## Electrical changes

As the micro Drivers Require ABI input for the tourque control, the encoders can output ABI, as well as SPI in order tp have the position input ready for the [Master-Board](https://github.com/open-dynamic-robot-initiative/master-board#master-board).

### Gerber Files
---
|PCB Schematic|Photograph|
|-------------|-------------|
| <img src="images\enocder_electronics.png" height="200"> | <img src="images\photo_encoder_board.jpg" height="200">|

* The gerber files for the encoder Bord can be found [Here](/Electrical-Changes)

---
### Bill of Material


| Part        | Description | Suppliers   |
|-------------|-------------|------------|
| AS5047 | main IC | [Mouser](mouser.com)|
| C1 | Cap. 0402 100 nf  | " |
| C2 | Cap. 0402 1 uf  | " |
| R1 | optional. 100R for LED_1  | " |
| LED_1 | 0402 LED  | " |


## Communication Via Arduino

I used the following [repository](https://github.com/adrien-legrand/AS5X47) to communicate with the AS5047 chip via SPI through an Arduino. The solder bridge labelled "Test" has to be closed for this. [Link](https://github.com/adrien-legrand/AS5X47)


