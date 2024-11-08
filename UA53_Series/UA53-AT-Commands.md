<img src="https://github.com/user-attachments/assets/771264bf-60dc-46db-bd62-2f0d790b0e11" width="40%" height="30%">

<html lang="en">
<head>
<h1> AT Commands Description for UA Sensors </h1> 
<p>Last Update: 05 NOV 2024, <a href="mailto:master@dekist.com">master@dekist.com</a></p>
  
<h2>Overview</h2>
<p> The Radionode USB Sensor transmitter series has simple text commands to read or set parameters of the sensor. The commands are very similar to AT commands of old-fashioned telephone modems. The UA series device has USB CDC (Communication Device Class) that makes it connectable to many operating systems such as Windows, Linux, MacOS, and Android via USB port. Simply with the command <code>ATCD</code>, the user can read the digital value of the sensor. All the UA series use the same command to read the sensors.</p>

<h2>1. UA53 Sensor Types</h2>
<table>
    <tr>
        <th>Model Group</th>
        <th>Model Description</th>
        <th>Type</th>
    </tr>
    <tr>
        <td>UA53 Series</td>
        <td>
          ElectroChemical Cell
          UA53-CO: Carbon Monoxide Sensor</br>
          UA53-SO2: Sulfur Dioxide Sensor</br>
          UA53-NO2: Nitrogen Dioxide Sensor</br>
          UA53-H2S: Hydrogen Sulfide Sensor</br>
        </td>
        <td>Temperature</td>
    </tr>
</table>

<h2>2. UA53 Series AT Commands</h2>
<p>The calibration parameters are not listed here. If you need the professional calibration commands, please contact the Radionode Manufacturer DEKIST Co., Ltd.</p>

<h3>Common Command Syntax</h3>
<li style="font-size: smaller;"> CR(\r), LF(\n)</li>

<h3>ATCZ</h3>
<p>It checks USB connection and device status.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>
            IN ATCZ&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCZ OK&lt;CR&gt;&lt;LF&gt;
        </td>
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
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA53_CO_1V0&lt;CR&gt;&lt;LF&gt;</td>
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
        <td>IN ATCMODEL&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODEL 20241108&lt;CR&gt;&lt;LF&gt;</td>
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
        <td>
            IN ATCD&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCD 5.23, 19.85&lt;CR&gt;&lt;LF&gt;
        </td>
        <td>
            To request the value of sensor data.<br>
            ATCD &lt;channel1&gt;,&lt;channel2&gt;<br>
            <ul style="list-style-type: none; padding-left: 0;">
                <li style="font-size: smaller;">channel1: Gas concentration [ppm]</li>
                <li style="font-size: smaller;">channel2: Temperature [°C/°F]</li>
            </ul>
        </td>
    </tr>
</table>

<h3>ATCQ</h3>
<p>To request the value of sensor data (four channels).</p>
<p>Example of UA53-CO:</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>
            IN ATCQ&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCQ 3.00, 26.00, 36.00, ----&lt;CR&gt;&lt;LF&gt;
        </td>
        <td>
            To request the value of sensor data.<br>
            ATCQ &lt;channel1&gt;,&lt;channel2&gt;,&lt;channel3&gt;,&lt;----&gt;<br>
            <ul style="list-style-type: none; padding-left: 0;">
                <li style="font-size: smaller;">channel1: CO [ppm]</li>
                <li style="font-size: smaller;">channel2: Temperature [°C or °F]</li>
                <li style="font-size: smaller;">channel3: Humidity [%]</li>
            </ul>
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


<h3>ATCCZR</h3>
<p>Set the zero (baseline) value.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>
            IN ATCCZR&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCCZR 1510.02&lt;CR&gt;&lt;LF&gt;
        </td>
        <td>Set the baseline value [Micro voltage].</td>
    </tr>
</table>

<h3>ATCCSP</h3>
<p>Set sensor-specific sensitivity (nA/ppm).</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>
            IN ATCCSP sensitivity&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCCSP 3055.12, 2.56, 24.17&lt;CR&gt;&lt;LF&gt;
        </td>
        <td>
            Set sensor-specific sensitivity.<br>
            ATCSP baseline, sensitivity, calibration temperature&lt;CR&gt;&lt;LF&gt;<br>
            <strong>Unit:</strong><br>
            baseline [zero]: [uV], sensitivity: [nA/ppm],<br>
            calibration temperature: [°C]
        </td>
    </tr>
</table>

<h3>ATCCAL</h3>
<p>Set the calibration parameter (calibration).</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>
            IN ATCCAL baseline, sensitivity&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCCAL 3055.12, 2.56&lt;CR&gt;&lt;LF&gt;
        </td>
        <td>
            Set the calibration parameter.<br>
            ATCCAL baseline, sensitivity&lt;CR&gt;&lt;LF&gt;<br>
            <strong>Unit:</strong><br>
            baseline [zero]: [uV], sensitivity: [nA/ppm]
        </td>
    </tr>
</table>

<h3>ATCOFFn(n=1~2)</h3>
<p>To set the offset value of channel n output.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>
            IN ATCOFF1 -0.5&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCOFF1 -0.5&lt;CR&gt;&lt;LF&gt;
        </td>
        <td>To set the offset value of channel 1 output.</td>
    </tr>
</table>
