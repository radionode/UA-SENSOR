<img src="https://github.com/user-attachments/assets/771264bf-60dc-46db-bd62-2f0d790b0e11" width="20%" height="10%">

<html lang="en">
<head>
<h1> AT Commands Description for UA1X Sensors </h1> 
<p>Last Update: 05 NOV 2024, <a href="mailto:master@dekist.com">master@dekist.com</a></p>
  
<h2>Overview</h2>
<p> The Radionode USB Sensor transmitter series has simple text commands to read or set parameters of the sensor. The commands are very similar to AT commands of old-fashioned telephone modems. The UA series device has USB CDC (Communication Device Class) that makes it connectable to many operating systems such as Windows, Linux, MacOS, and Android via USB port. Simply with the command <code>ATCD</code>, the user can read the digital value of the sensor. All the UA series use the same command to read the sensors.</p>

<h2>1. UA1X Sensor Types</h2>
<table>
    <tr>
        <th>Model Group</th>
        <th>Model Description</th>
        <th>Type</th>
    </tr>
    <tr>
        <td>UA1X Series</td>
        <td>
            UA10: Temp/ RH<br>
            UA11: Thermocouple Temp 2CH (T,K)<br>
            UA12: Thermocouple Temp 2CH (K,J,T,N,S,E,B,R)<br>
            UA13: PT100 Temp. 1CH
        </td>
        <td>Temperature</td>
    </tr>
</table>

<h2>2. UA1X Series AT Commands</h2>
<p>The calibration parameters are not listed here. If you need the professional calibration commands, please contact the Radionode Manufacturer DEKIST Co., Ltd.</p>

<h3>Common Command Syntax</h3>
<li style="font-size: smaller;"> CR(\r), LF(\n)</li>

<h3>ATCZ</h3>
<p>To request the value of sensor data (two channels).</p>
<table class="table" border="1" style="table-layout: fixed">
    <table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCZ&lt;CR&gt;&lt;LF&gt;<br>OUT ATCZ OK&lt;CR&gt;&lt;LF&gt;</td>
        <td>It checks USB connection.</td>
    </tr>
</table>

<h3>ATCVER</h3>
<p>To request the version of this device.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA10H_1V0&lt;CR&gt;&lt;LF&gt;</td>
        <td>To request the version of this device.</td>
    </tr>
</table>

<h3>ATCMODEL</h3>
<p>To request the serial number of this model.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCMODEL&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODEL 17091345&lt;CR&gt;&lt;LF&gt;</td>
        <td>To request the serial number of this model.</td>
    </tr>
</table>

<h3>ATCD</h3>
<p>To request the value of sensor data (two channels).</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCD&lt;CR&gt;&lt;LF&gt;<br>OUT ATCD 20.11, 23.44&lt;CR&gt;&lt;LF&gt;</td>
        <td>To request the value of sensor data.<br>
            ATCD &lt;channel1&gt;,&lt;channel2&gt;<br>
            <ul style="list-style-type: none; padding-left: 0;">
                <li style="font-size: smaller;">&lt;channel1&gt;</code> = Temperature</li>
                <li style="font-size: smaller;">&lt;channel2&gt;</code> = RH or Temperature</li>
                <li style="font-size: smaller;">UA10: &lt;ch1=Temperature&gt;&lt;ch2=Humidity&gt;</li>
                <li style="font-size: smaller;">UA11: &lt;ch1=Temperature&gt;&lt;ch2=Temperature&gt;</li>
                <li style="font-size: smaller;">UA20: &lt;ch1=user defined&gt;&lt;ch2=user defined&gt;</li>
            </ul>
        </td>
    </tr>
</table>

<h3>ATCSM</h3>
<p>To enable stream mode; the UA1X sends sensor values every second without needing any user command. All channels will output data. This mode is currently supported only for the UA10.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCSM 1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCSM OK&lt;CR&gt;&lt;LF&gt;<br>OUT STREAM 12.33, 34.56&lt;CR&gt;&lt;LF&gt;</td>
        <td>To enable stream mode (1:Enable, 0:Disable).<br>
          The below string will be output automatically every 1 sec:<br>
         <li style="font-size: smaller;">ATCSM &lt;channel1&gt;,&lt;channel2&gt;</li>
        </td>
    </tr>
</table>

<h3>ATCC</h3>
<p>To set Celsius temperature.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCC&lt;CR&gt;&lt;LF&gt;<br>OUT ATCC OK&lt;CR&gt;&lt;LF&gt;</td>
        <td>To set Celsius temperature scale.</td>
    </tr>
</table>

<h3>ATCF</h3>
<p>To set Fahrenheit temperature.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCF&lt;CR&gt;&lt;LF&gt;<br>OUT ATCF OK&lt;CR&gt;&lt;LF&gt;</td>
        <td>To set Fahrenheit temperature scale.</td>
    </tr>
</table>

<h3>ATCOFF1</h3>
<p>To set the offset value of channel 1 output.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCOFF1 -0.5&lt;CR&gt;&lt;LF&gt;<br>OUT ATCOFF1 -0.5&lt;CR&gt;&lt;LF&gt;</td>
        <td>To set the offset value of channel 1 output.</td>
    </tr>
</table>

<h3>ATCOFF2</h3>
<p>To set the offset value of channel 2 output.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCOFF2 -0.5&lt;CR&gt;&lt;LF&gt;<br>OUT ATCOFF2 -0.5&lt;CR&gt;&lt;LF&gt;</td>
        <td>To set the offset value of channel 2 output.</td>
    </tr>
</table>
<img src= https://github.com/user-attachments/assets/19be74aa-b7b7-4f81-8396-aed602f40030>

<h3>ATTQOFF1</h3>
<p>To set Temperature Offset in AREA1. <strong>Only For UA10H Ver1.0 or later.</strong></p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATTQOFF1 30,1.54,-0.004&lt;CR&gt;&lt;LF&gt;<br>OUT ATTQOFF1 30,1.54,-0.004&lt;CR&gt;&lt;LF&gt;</td>
        <td>To set Temperature Offset in AREA1. It is a quadratic equation offset algorithm.</td>
    </tr>
</table>

<h3>ATTQOFF2</h3>
<p>To set Temperature Offset in AREA2. <strong>Only For UA10H Ver1.0 or later.</strong></p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATTQOFF2 30,1.54,-0.004&lt;CR&gt;&lt;LF&gt;<br>OUT ATTQOFF2 30,1.54,-0.004&lt;CR&gt;&lt;LF&gt;</td>
        <td>To set Temperature Offset in AREA2. It is a quadratic equation offset algorithm.</td>
    </tr>
</table>

<h3>ATHQOFF1</h3>
<p>To set Humidity Offset in AREA1. <strong>Only For UA10H Ver1.0 or later.</strong></p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATHQOFF1 30,1.54,-0.004&lt;CR&gt;&lt;LF&gt;<br>OUT ATHQOFF1 30,1.54,-0.004&lt;CR&gt;&lt;LF&gt;</td>
        <td>To set Humidity Offset in AREA1. It is a quadratic equation offset algorithm.</td>
    </tr>
</table>

<h3>ATHQOFF2</h3>
<p>To set Humidity Offset in AREA2. <strong>Only For UA10H Ver1.0 or later.</strong></p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATHQOFF2 30,1.54,-0.004&lt;CR&gt;&lt;LF&gt;<br>OUT ATHQOFF2 30,1.54,-0.004&lt;CR&gt;&lt;LF&gt;</td>
        <td>To set Humidity Offset in AREA2. It is a quadratic equation offset algorithm.</td>
    </tr>
</table>

<h3>ATCCH1WIN</h3>
<p>Digital Filter Weight Value for Channel 1. <strong>Only For UA10H, UA11, UA13.</strong></p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCH1WIN 4&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCH1WIN 4&lt;CR&gt;&lt;LF&gt;</td>
        <td>To Set or To Get filter parameters 1~ 15.<br>
        <li style="font-size: smaller;">1: the highest sensitivity (fast)</li>
        <li style="font-size: smaller;">15: insensitivity (slow)</li>
        </td>
    </tr>
</table>

<h3>ATCCH2WIN</h3>
<p>Digital Filter Weight Value for Channel 2. <strong>Only For UA10H, UA11, UA13.</strong></p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCH2WIN&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCH2WIN 14&lt;CR&gt;&lt;LF&gt;</td>
        <td>To Set or To Get filter parameters 1~ 15.<br>
        <li style="font-size: smaller;">1: the highest sensitivity (fast)</li>
        <li style="font-size: smaller;">15: insensitivity (slow)</li>
        </td>
    </tr>
</table>

<h3>ATCCTS1</h3>
<p>Sensor type (thermocouple) setting for Channel 1. <strong>Only For UA12.</strong></p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCTS1 4&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCTS1 4&lt;CR&gt;&lt;LF&gt;</td>
        <td>To Set or To Get sensor type -1 ~ 7:<br>
            <ul style="list-style-type: none; padding-left: 0;">
                <li style="font-size: smaller;">-1: Type None</li>
                <li style="font-size: smaller;">0: K Type</li>
                <li style="font-size: smaller;">1: J Type</li>
                <li style="font-size: smaller;">2: T Type</li>
                <li style="font-size: smaller;">3: N Type</li>
                <li style="font-size: smaller;">4: S Type</li>
                <li style="font-size: smaller;">5: E Type</li>
                <li style="font-size: smaller;">6: B Type</li>
                <li style="font-size: smaller;">7: R Type</li>
            </ul>
        </td>
    </tr>
</table>

<h3>ATCCTS2</h3>
<p>Sensor type (thermocouple) setting for Channel 2. <strong>Only For UA12.</strong></p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCTS2 7&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCTS2 7&lt;CR&gt;&lt;LF&gt;</td>
        <td>To Set or To Get sensor type -1 ~ 7:<br>
            <ul style="list-style-type: none; padding-left: 0;">
                <li style="font-size: smaller;">-1: Type None</li>
                <li style="font-size: smaller;">0: K Type</li>
                <li style="font-size: smaller;">1: J Type</li>
                <li style="font-size: smaller;">2: T Type</li>
                <li style="font-size: smaller;">3: N Type</li>
                <li style="font-size: smaller;">4: S Type</li>
                <li style="font-size: smaller;">5: E Type</li>
                <li style="font-size: smaller;">6: B Type</li>
                <li style="font-size: smaller;">7: R Type</li>
            </ul>
        </td>
    </tr>
</table>

</body>
</html>
