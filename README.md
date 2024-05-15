# Muqaddimah
Six-step commutation, also known as trapezoidal commutation, is a commutation technique used to control three-phase brushless DC (BLDC) permanent magnet motor. 
It controls the stator currents to achieve a motor speed and direction of rotation.

# Hardware Requirements
- Arduino UNO <br/>
  <img src="https://github.com/zulfiar-am/six-step-commutation/assets/63053239/3cfb10b2-f3c1-43d6-b9a6-64da90646957" width="400" height="250">

- DRV8302 Motor Driver Module by Zonri Tech <br/>
  <img src="https://github.com/zulfiar-am/six-step-commutation/assets/63053239/7e5b1d96-519d-42d0-9e17-71848dd53193" width="400" height="250">
  
- Any BLDC Motor with 3 Hall Sensor

# Hardware Connection
Arduino UNO to DRV8302 <br/>
<table>
  <tr>
    <th>Arduino UNO</th>
    <th>DRV8302</th>
  </tr>
  <tr>
    <td>D1</td>
    <td>EN</td>
  </tr>
  <tr>
    <td>D5</td>
    <td>M_PWM</td>
  </tr>
  <tr>
    <td>D6</td>
    <td>M_OC</td>
  </tr>
  <tr>
    <td>D7</td>
    <td>OC_ADJ</td>
  </tr>
   <tr>
    <td>D8</td>
    <td>HA</td>
  </tr>
   <tr>
    <td>D9</td>
    <td>HB</td>
  </tr>
   <tr>
    <td>D10</td>
    <td>HC</td>
  </tr>
   <tr>
    <td>D11</td>
    <td>LA</td>
  </tr>
   <tr>
    <td>D12</td>
    <td>LB</td>
  </tr>
   <tr>
    <td>D13</td>
    <td>LC</td>
  </tr>
<table/>
Arduino UNO to BLDC Motor <br/>
  <table>
  <tr>
    <th>Arduino UNO</th>
    <th>BLDC Motor</th>
  </tr>
  <tr>
    <td>D2</td>
    <td>HALL_U</td>
  </tr>
  <tr>
    <td>D3</td>
    <td>HALL_V</td>
  </tr>
  <tr>
    <td>D4</td>
    <td>HALL_W</td>
  </tr>
  <table/>
  DRV8302 Module to BLDC Motor <br/>
  <table>
  <tr>
    <th>DRV8302</th>
    <th>BLDC Motor</th>
  </tr>
  <tr>
    <td>OUTA</td>
    <td>U PHASE</td>
  </tr>
  <tr>
    <td>OUTB</td>
    <td>V PHASE</td>
  </tr>
  <tr>
    <td>OUTC</td>
    <td>W PHASE</td>
  </tr>
  <table/>

  # How it works?
  This program uses a commutation logic based on the position sensor signals (Hall Sensor) to generate switching sequences. <br/>
  for further explanation you could refer to this article: <br/>
  https://www.mathworks.com/help/mcb/ref/sixstepcommutation.html

  # Conclusion
  This program has been tested and worked successfully on Arduino UNO and Arduino DUE <br/>
  You could see the difference of both controller from the video below: <br/>
  - https://m.youtube.com/shorts/E6k92-TUxWU
  - https://m.youtube.com/shorts/I4uwIdeBnro
  
  # Further Development
  I compared this simple program with Modified Direct Torque Control for my undergraduate thesis. <br/>
  https://repository.its.ac.id/98705/
  
  # References
  - https://www.mathworks.com/help/mcb/ref/sixstepcommutation.html
  - https://docs.simplefoc.com/drv8302_example
  

  
