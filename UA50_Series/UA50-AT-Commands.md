<img src="https://github.com/user-attachments/assets/771264bf-60dc-46db-bd62-2f0d790b0e11" width="20%" height="10%">

<body>

<h1>AT Commands Description for UA50 Series Sensors</h1>
<p>Last Update: 05 NOV 2024, <a href="mailto:master@dekist.com">master@dekist.com</a></p>

<hr>

<h2>Overview</h2>
<p>The Radionode USB Sensor transmitter series has simple text commands to read or set parameters of the sensor. The commands are very similar to AT commands of old-fashioned telephone modems. The UA series device has USB CDC (Communication Device Class) that makes it connectable to many operating systems such as Windows, Linux, MacOS, and Android via USB port.<br>
  Simply with the command ATCD, the user can read the digital value of the sensor. All the UA series use the same command to read the sensors.</p>

<h2>1. UA50 Sensor Types</h2>
<table>
    <tr>
        <th>Model Group</th>
        <th>Model Description</th>
        <th>Type</th>
    </tr>
    <tr>
        <td>UA50 Series</td>
        <td>
		MEMS Type<br>
		UA50: tVOC sensor<br>
        </td>
        <td>Gas</td>
    </tr>
</table>

<h2>2. UA50 (VoC Gas) AT Commands</h2>
<p>The calibration parameters are not listed here. If you need the professional calibration commands, please contact the Radionode Manufacturer DEKIST Co., Ltd.</p>
<li style="font-size: smaller;"> CR(\r), LF(\n)</li>

<h3>ATCZ</h3>
<p>It checks USB connection and device status.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCZ&lt;CR&gt;&lt;LF&gt;<br>OUT ATCZ OK&lt;CR&gt;&lt;LF&gt;</td>
        <td>Checks USB Connection.</td>
    </tr>
</table>

<h3>ATCD</h3>
<p>To request the value of sensor data (two channels)</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
  	<td>IN: ATCD&lt;CR&gt;&lt;LF&gt;<br>OUT: ATCD 20.11, 23.44&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests sensor data: ATCD &lt;channel1&gt;,&lt;channel2&gt;</td>
        </td>
    </tr>
</table>

   <h2>ATCQ</h2>
    <p>To request the value of sensor data (four channels).</p>
    <table border="1">
        <tr>
            <th>Example</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>IN: ATCQ&lt;CR&gt;&lt;LF&gt;<br>OUT: ATCQ 1.11,5.11,1113----&lt;CR&gt;&lt;LF&gt;</td>
            <td>Requests sensor data: ATCQ &lt;channel1&gt;,&lt;channel2&gt;&lt;channel3&gt;, ...<br>
                <ul>
                    <li>channel1: TVOC [ppm or ppb]</li>
                    <li>channel2: Absolute humidity [g/m<sup>3</sup>]</li>
                    <li>channel3: CO2-equivalent [ppm or %]</li>
                </ul>
            </td>
        </tr>
    </table>

<h3>ATCC</h3>
<p>To set Celsius temperature</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCC&lt;CR&gt;&lt;LF&gt;<br>OUT ATCC OK&lt;CR&gt;&lt;LF&gt;</td>
        <td>Sets Celsius temperature scale.</td>
    </tr>
</table>

<h3>ATCF</h3>
<p>To set Fahrenheit temperature</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCF&lt;CR&gt;&lt;LF&gt;<br>OUT ATCF OK&lt;CR&gt;&lt;LF&gt;</td>
        <td>Sets Fahrenheit temperature scale.</td>
    </tr>
</table>

<h3>ATCVER</h3>
<p>To request the version of this device</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA50_1V4&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests the version of this device (e.g.,  UA50_1V4).</td>
    </tr>
</table>

<h3>ATCMODEL</h3>
<p>To request the serial number of this model</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCMODEL&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODEL 20241111&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests the serial number of this model.</td>
    </tr>
</table>

<h2>ATCVOCU</h2>
    <p>To change the CO2 output unit of ATCD command.</p>
<table>
        <tr>
            <th>Example</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>IN: ATCVOCU 0&lt;CR&gt;&lt;LF&gt;<br>OUT: ATCVOCU 0&lt;CR&gt;&lt;LF&gt;<br>IN: ATCVOCU 1&lt;CR&gt;&lt;LF&gt;<br>OUT: ATCVOCU 1&lt;CR&gt;&lt;LF&gt;</td>
            <td>Changes the TVOC output unit: ppm (0) or ppb (1).</td>
        </tr>
</table>

<h2>ATCCU</h2>
    <p>To change the CO2-equivalent output unit of ATCD command.</p>
<table>
        <tr>
            <th>Example</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>IN: ATCCU 0&lt;CR&gt;&lt;LF&gt;<br>OUT: ATCCU 0&lt;CR&gt;&lt;LF&gt;<br>IN: ATCCU 1&lt;CR&gt;&lt;LF&gt;<br>OUT: ATCCU 1&lt;CR&gt;&lt;LF&gt;</td>
            <td>Changes the CO2-equivalent output unit: % (0) or ppm (1).</td>
        </tr>
</table>

<h2>ATCOFF1</h2>
<p>To set the offset value of channel 1 output.</p>
<table>
        <tr>
            <th>Example</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>IN: ATCOFF1 -0.5&lt;CR&gt;&lt;LF&gt;<br>OUT: ATCOFF1 -0.5&lt;CR&gt;&lt;LF&gt;</td>
            <td>Sets the offset value of channel 1 output.</td>
        </tr>
</table>

<h2>ATCOFF2</h2>
<p>To set the offset value of channel 2 output.</p>
<table>
        <tr>
            <th>Example</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>IN: ATCOFF2 -0.5&lt;CR&gt;&lt;LF&gt;<br>OUT: ATCOFF2 -0.5&lt;CR&gt;&lt;LF&gt;</td>
            <td>Sets the offset value of channel 2 output.</td>
        </tr>
</table>
</body>
</html>