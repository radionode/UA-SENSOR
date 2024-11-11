<img src="https://github.com/user-attachments/assets/771264bf-60dc-46db-bd62-2f0d790b0e11" width="20%" height="10%">

<body>

<h1>AT Commands Description for UA54 Series Sensors</h1>
<p>Last Update: 05 NOV 2024, <a href="mailto:master@dekist.com">master@dekist.com</a></p>

<hr>

<h2>Overview</h2>
<p>The Radionode USB Sensor transmitter series has simple text commands to read or set parameters of the sensor. The commands are very similar to AT commands of old-fashioned telephone modems. The UA series device has USB CDC (Communication Device Class) that makes it connectable to many operating systems such as Windows, Linux, MacOS, and Android via USB port.<br>
  Simply with the command <code>ATCD</code>, the user can read the digital value of the sensor. All the UA series use the same command to read the sensors.</p>

<h2>1. UA54 Sensor Types</h2>
<table>
    <tr>
        <th>Model Group</th>
        <th>Model Description</th>
        <th>Type</th>
    </tr>
    <tr>
        <td>UA54 Series</td>
        <td>
            ElectroChemical Cell<br>
            UA54-NH3: Ammonia Sensor<br>
            UA54-H2S: Hydrogen Sulfide Sensor<br>
            UA54-EO: Ethylene Oxide Sensor<br>
            UA54-HCL: Hydrogen Chloride Sensor<br>
            UA54-C2H4: Ethylene Sensor
        </td>
        <td>Gas</td>
    </tr>
</table>

<h2>2. UA54 Series AT Commands</h2>
<p>The calibration parameters are not listed here. If you need the professional calibration commands, please contact the Radionode Manufacturer DEKIST Co., Ltd.</p>
<li style="font-size: smaller;"> CR(\r), LF(\n)</li>

<h3>ATCD</h3>
<p>To request the value of sensor data (two channels).</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCD&lt;CR&gt;&lt;LF&gt;<br>OUT ATCD 5.23, 19.85&lt;CR&gt;&lt;LF&gt;</td>
        <td>To request the value of sensor data.<br>
            ATCD &lt;channel1&gt;,&lt;channel2&gt;<br>
            • channel1 : Gas concentration [ppm]<br>
            • O2 model : Gas concentration [%]<br>
            • H2 model: Gas concentration [%] or LEL (Lower explosive level)<br>
            • channel2 : Temperature [°C/°F]
        </td>
    </tr>
</table>

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

<h3>ATCHLEL</h3>
<p>To request H2 % concentration or H2 LEL.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCHLEL 0&lt;CR&gt;&lt;LF&gt;<br>OUT ATCHLEL 0&lt;CR&gt;&lt;LF&gt;<br>
            IN ATCHLEL 1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCHLEL 1&lt;CR&gt;&lt;LF&gt;</td>
        <td>To request H2 % concentration (default value) or to request H2 LEL.</td>
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
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA54-Gas_5V3&lt;CR&gt;&lt;LF&gt;</td>
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

<h3>ATCCZR</h3>
<p>Set the zero (baseline) value.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCZR&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCZR 7510.02&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set the baseline value [Micro voltage].</td>
    </tr>
</table>

<h3>ATCCSP</h3>
<p>Set the span value for gas concentration.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>
            IN ATCCSP Gas concentration&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCCSP 5.00, 0.000036, 23055.12, 162526.09, 24.17&lt;CR&gt;&lt;LF&gt;
        </td>
        <td>
            Set the calibration gas concentration.<br>
            ATCSP calibration gas, calibration slope, baseline, span,<br>
            calibration temperature.<br>
            <strong>Unit:</strong><br>
            • calibration gas: [ppm],<br>
            • calibration slope: [ppm/uV],<br>
            • baseline [zero]: [uV],<br>
            • span: [uV],<br>
            • calibration temperature: [°C]
        </td>
    </tr>
</table>

<h3>ATCCAL</h3>
<p>(Calibration) Set the calibration parameter.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCCAL baseline,span,calibration gas&lt;CR&gt;&lt;LF&gt;<br>OUT ATCCAL 23055.12,162526.09,5.00&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set the calibration parameter.<br>
            ATCCAL baseline, span, calibration gas&lt;CR&gt;&lt;LF&gt;<br>
            <strong>Unit:</strong><br>
            • baseline[zero]: [uV], span: [uV], calibration gas: [ppm]
        </td>
    </
