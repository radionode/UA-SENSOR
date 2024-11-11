

<img src="https://github.com/user-attachments/assets/771264bf-60dc-46db-bd62-2f0d790b0e11" width="40%" height="30%">

<body>

<h1>AT Commands Description for UA58 Series Sensors</h1>
<p>Last Update: 05 NOV 2024, <a href="mailto:master@dekist.com">master@dekist.com</a></p>

<hr>

<h2>Overview</h2>
<p>The Radionode USB Sensor transmitter series has simple text commands to read or set parameters of the sensor. The commands are very similar to AT commands of old-fashioned telephone modems. The UA series device has USB CDC (Communication Device Class) that makes it connectable to many operating systems such as Windows, Linux, MacOS, and Android via USB port.<br>
  Simply with the command <code>ATCD</code>, the user can read the digital value of the sensor. All the UA series use the same command to read the sensors.</p>

<h2>1. UA58 Sensor Types</h2>
<table>
    <tr>
        <th>Model Group</th>
        <th>Model Description</th>
        <th>Type</th>
    </tr>
    <tr>
        <td>UA58 Series</td>
        <td>
            ElectroChemical Cell<br>
            UA58-KFG (CO, O2, H2S, CO2)<br>
            UA58-LEL (flammable gas)<br>
            UA58-Methane<br>
        </td>
        <td>Gas</td>
    </tr>
</table>

<h2>2. UA58 Series AT Commands</h2>
<p>The calibration parameters are not listed here. If you need the professional calibration commands, please contact the Radionode Manufacturer DEKIST Co., Ltd.</p>
<li style="font-size: smaller;"> CR(\r), LF(\n)</li>

<h2>2-1 UA58-KFG (Multi Purpose Gas Sensor) AT Commands</h2>

<h3>ATCZ</h3>
<p>To check USB connection and device status.</p>
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

<h3>ATCD</h3>
<p>To request the value of sensor data (two channels).</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCD&lt;CR&gt;&lt;LF&gt;<br>OUT ATCD 5.23, 20.8&lt;CR&gt;&lt;LF&gt;</td>
        <td>To request the value of sensor data.<br>
            ATCD &lt;channel1&gt;,&lt;channel2&gt;<br>
            • ch1: Carbon monoxide gas concentration [ppm]<br>
            • ch2: Oxygen gas concentration [%]<br>
        </td>
    </tr>
</table>

<h3>ATCQ</h3>
<p>To request the value of sensor data (four channels)</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCQ&lt;CR&gt;&lt;LF&gt;<br>OUT ATCQ 5.23,20.8,10.2,989&lt;CR&gt;&lt;LF&gt;</td>
        <td>To request the value of sensor data.<br>
            ATCQ &lt;channel1&gt;,&lt;channel2&gt;,&lt;channel3&gt;,&lt;channel4&gt;<br>
            • ch1: Carbon monoxide gas concentration [ppm]<br>
            • ch2: Oxygen gas concentration [%]<br>
            • ch3: Hydrogen sulfide gas concentration [ppm]<br>
            • ch4: Carbon dioxide gas concentration [ppm]
        </td>
    </tr>
</table>

<h3>ATCH</h3>
<p>To request the value of sensor data (six channels)</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCH&lt;CR&gt;&lt;LF&gt;<br>OUT ATCH 5.23,20.8,10.2,989,25.1,50.5&lt;CR&gt;&lt;LF&gt;</td>
        <td>To request the value of sensor data.<br>
            ATCH &lt;channel1&gt;,&lt;channel2&gt;,&lt;channel3&gt;,&lt;channel4&gt;,&lt;channel5&gt;,&lt;channel6&gt;<br>
            • ch1: Carbon monoxide gas concentration [ppm]<br>
            • ch2: Oxygen gas concentration [%]<br>
            • ch3: Hydrogen sulfide gas concentration [ppm]<br>
            • ch4: Carbon dioxide gas concentration [ppm]<br>
            • ch5: Temperature [°C]<br>
            • ch6: Humidity [%]
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

<h3>ATCVER</h3>
<p>To request the version of this device.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA58-KFG_5V3&lt;CR&gt;&lt;LF&gt;</td>
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
        <td>IN ATCMODEL&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODEL 241105&lt;CR&gt;&lt;LF&gt;</td>
        <td>To request the serial number of this model.</td>
    </tr>
</table>

<h3>ATCCZRA</h3>
<p>Set the zero (baseline) value from channel 1 to channel 3</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCZRA&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCZRA 7510.02,1020.22,98763.12&lt;CR&gt;&lt;LF&gt;</td>
        <td>Sets the zero (baseline) value from channel 1 to channel 3 [Micro voltage]</td>
    </tr>
</table>

<h3>ATCCZRn (n=1~3)</h3>
<p>Set the zero (baseline) value for channel n</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCZR1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCZR1 7510.02&lt;CR&gt;&lt;LF&gt;</td>
        <td>Sets the zero (baseline) value for channel 1 [Micro voltage]</td>
    </tr>
</table>
<p>* An error is returned for channels other than 1 to 3</p>

<h3>ATCCSPn (n=1~3)</h3>
<p>Set the span value for channel n gas concentration</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCSP2 Calibration gas&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCSP2 5.00,0.000036,23055.12,162526.09,24.17&lt;CR&gt;&lt;LF&gt;</td>
        <td>Sets the span value for channel 2 gas concentration<br>
            • Calibration gas : [ppm]<br>
            • Calibration slope: [ppm(%)/uV]<br>
            • Baseline[zero]: [uV]<br>
            • Span: [uV]<br>
            • Calibration temperature: [°C]
        </td>
    </tr>
</table>
<p>* An error is returned for channels other than 1 to 3</p>

<h3>ATCCALn (n=1~3)</h3>
<p>Set the calibration parameter for channel n (Gas calibration)</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCAL3 Baseline,Span,Calibration gas&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCAL3 3055.12,162526.09,50.00&lt;CR&gt;&lt;LF&gt;</td>
        <td>Sets the calibration parameters for channel 3<br>
            • Baseline[zero]: [uV]<br>
            • Span: [uV]<br>
            • Calibration gas: [ppm]
        </td>
    </tr>
</table>
<p>* An error is returned for channels other than 1 to 3</p>

<h3>ATCZCAL</h3>
<p>Set the zero (baseline) value for channel 4 (Carbon dioxide)</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCZCAL&lt;CR&gt;&lt;LF&gt;<br>OUT ATCZCAL OK&lt;CR&gt;&lt;LF&gt;</td>
        <td>Sets the zero (400 ppm) baseline value for channel 4 (Carbon dioxide)</td>
    </tr>
</table>

<h3>ATCOFFn (n=1~6)</h3>
<p>Set the offset value of channel n output</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCOFF6 -0.5&lt;CR&gt;&lt;LF&gt;<br>OUT ATCOFF6 -0.5&lt;CR&gt;&lt;LF&gt;</td>
        <td>Sets the offset value of channel 6 output.<br>
            • ch1: ppm offset value (Carbon monoxide)<br>
            • ch2: % offset value (Oxygen)<br>
            • ch3: ppm offset value (Hydrogen sulfide)<br>
            • ch4: ppm offset value (Carbon dioxide)<br>
            • ch5: °C/°F offset value (Temperature)<br>
            • ch6: % offset value (Relative humidity)
        </td>
    </tr>
</table>
<p>* An error is returned for channels other than 1 to 6</p>
<h2>2-2 UA58-LEL (Flammable Gas) AT Commands</h2>

<h3>ATCZ</h3>
<p>It checks USB connection and device status.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCZ&lt;CR&gt;&lt;LF&gt;<br>OUT ATCZ OK&lt;CR&gt;&lt;LF&gt;</td>
        <td>Checks USB connection.</td>
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
        <td>IN ATCD&lt;CR&gt;&lt;LF&gt;<br>OUT ATCD 0.01, 25.00&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests sensor data: ATCD &lt;channel1&gt;,&lt;channel2&gt;<br>
            • channel1: Flammable gas concentration [%LEL]<br>
            • channel2: Temperature [°C/°F]
        </td>
    </tr>
</table>

<h3>ATCQ</h3>
<p>To request the value of sensor data (four channels)</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCQ&lt;CR&gt;&lt;LF&gt;<br>OUT ATCQ 48.7,26.00,36.00,3&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests sensor data: ATCQ &lt;channel1&gt;,&lt;channel2&gt;,&lt;channel3&gt;,&lt;channel4&gt;<br>
            • channel1: Flammable gas concentration [%LEL]<br>
            • channel2: Temperature [°C/°F]<br>
            • channel3: Humidity [%]<br>
            • channel4: Gas ID<br>
            <br>
            <strong>Gas ID values:</strong><br>
            0: No gas, 1: Hydrogen, 2: Hydrogen Mixture, 3: Methane, 4: Light Gas, 5: Medium Gas<br>
            6: Heavy Gas, 253: Unknown Gas, 254: Under Range (-5%LEL), 255: Over Range (100%LEL)<br>
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

<h3>ATCMODE</h3>
<p>To change the sensor output mode of ATCD command to the international standard output mode.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCMODE 0&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODE 0&lt;CR&gt;&lt;LF&gt;<br>IN ATCMODE 1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODE 1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Changes sensor output mode:<br>
            • MODE0: ISO (%LEL)<br>
            • MODE1: IEC (%LEL)
        </td>
    </tr>
</table>

<h3>ATCID</h3>
<p>Flammable gas ID as determined by the sensor</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCID&lt;CR&gt;&lt;LF&gt;<br>OUT ATCID 1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Flammable gas ID:<br>
            • 1: Hydrogen, 2: Hydrogen Mixture, 3: Methane, 4: Light Gas, 5: Medium Gas, 6: Heavy Gas
        </td>
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
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA58-LEL_0v1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests device version (e.g., UA58-LEL_0V1).</td>
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
        <td>IN ATCMODEL&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODEL 20240901&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests model serial number.</td>
    </tr>
</table>

<h2>UA58-CH4 (Methane Sensor) AT Commands</h2>

<h3>ATCZ</h3>
<p>It checks USB connection and device status.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCZ&lt;CR&gt;&lt;LF&gt;<br>OUT ATCZ OK&lt;CR&gt;&lt;LF&gt;</td>
        <td>Checks USB connection.</td>
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
        <td>IN ATCD&lt;CR&gt;&lt;LF&gt;<br>OUT ATCD 5.23, 19.85&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests sensor data: ATCD &lt;channel1&gt;,&lt;channel2&gt;<br>
            • channel1: Methane concentration [ppm]<br>
            • channel2: Temperature [°C/°F]
        </td>
    </tr>
</table>

<h3>ATCQ</h3>
<p>To request the value of sensor data (four channels)</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCQ&lt;CR&gt;&lt;LF&gt;<br>OUT ATCQ 3.00,26.00,36.00,----&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests sensor data: ATCQ &lt;channel1&gt;,&lt;channel2&gt;,&lt;channel3&gt;<br>
            • channel1: Methane concentration [ppm]<br>
            • channel2: Temperature [°C/°F]<br>
            • channel3: Humidity [%]
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
<p>To request the version of this device.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA58-CH4_0v1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests device version (e.g., UA58-CH4_0V1).</td>
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
        <td>IN ATCMODEL&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODEL 20240130&lt;CR&gt;&lt;LF&gt;</td>
        <td>Requests model serial number.</td>
    </tr>
</table>

<h3>ATCOFFn (n=1~2)</h3>
<p>To set the offset value of channel n output</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCOFF1 -0.5&lt;CR&gt;&lt;LF&gt;<br>OUT ATCOFF1 -0.5&lt;CR&gt;&lt;LF&gt;</td>
        <td>Sets offset value of channel 1 output.</td>
    </tr>
</table>
