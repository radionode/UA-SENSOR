
<img src="https://github.com/user-attachments/assets/771264bf-60dc-46db-bd62-2f0d790b0e11" width="20%" height="10%">

<body>

<h1>AT Commands Description for UA20 Series Sensors</h1>
<p>Last Update: 05 NOV 2024, <a href="mailto:master@dekist.com">master@dekist.com</a></p>

<hr>

<h2>Overview</h2>
<p>The Radionode USB Sensor transmitter series has simple text commands to read or set parameters of the sensor. The commands are very similar to AT commands of old-fashioned telephone modems. The UA series device has USB CDC (Communication Device Class) that makes it connectable to many operating systems such as Windows, Linux, MacOS, and Android via USB port.<br>
  Simply with the command <code>ATCD</code>, the user can read the digital value of the sensor. All the UA series use the same command to read the sensors.</p>

<h2>1. UA20 Sensor Types</h2>
<table>
    <tr>
        <th>Model Group</th>
        <th>Model Description</th>
        <th>Type</th>
    </tr>
    <tr>
        <td>UA20 Series</td>
        <td>
        UA20-A: 4-20mA Input  2CH<br>
        UA20-B: 4-20mA Input 1 CH with 12V output 1CH<br>
        UA20-C: 0~1V Input  2CH<br>
        UA20-D: Pulse Input<br> 
        UA20-E: CH1~6 for MODBUS RTU RS485 in MASTER MODE
        </td>
        <td>Signal Converter</td>
    </tr>
</table>

<h2>2. UA20-A~C AT Commands</h2>
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
        <td>
            IN ATCD&lt;CR&gt;&lt;LF&gt;<br>
           <p>OUT ATCD 20.11, 23.44&lt;CR&gt;&lt;LF&gt;</p>
        </td>
        <td>
            To request the value of sensor data.<br>
            ATCD &lt;channel1&gt;,&lt;channel2&gt;<br>
            - &lt;ch1&gt; = user defined<br>
            - &lt;ch2&gt; = user defined<br>
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

<h3>ATCVER</h3>
<p>To request the version of this device.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA20-A_1V3&lt;CR&gt;&lt;LF&gt;</td>
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

<h2>3.UA20-D AT Commands</h2>
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
        <td>
            IN ATCD&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCD 0&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCD 1&lt;CR&gt;&lt;LF&gt;:
        </td>
        <td>
            To request the value of sensor data.<br>
            ATCD &lt;channel1&gt;<br>
            - &lt;ch1&gt; = Pulse Count<br>
        </td>
    </tr>
</table>

<h3>ATCSM</h3>
<p>To enable stream mode; the UA1X sends sensor values every second without needing any user command. All channels will output data. This mode is currently supported only for the UA20D.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>
            IN ATCSM 1&lt;CR&gt;&lt;LF&gt;<br>
            <p>IN ATCSM 0&lt;CR&gt;&lt;LF&gt;</P>
            OUT ATCSM OK&lt;CR&gt;&lt;LF&gt;<br>
            <p>OUT ATCSM OFF&lt;CR&gt;&lt;LF></P>
            <p>OUT ATCSM 1&lt;CR&gt;&lt;LF&gt;</P>
            OUT 2<br>
            OUT ：
        </td>
        <td>To enable stream mode (1:Enable, 0:Disable).<br>
          The below string will be output automatically every 1 sec:<br>
         <li style="font-size: smaller;">ATCSM &lt;channel1&gt;,&lt;channel2&gt;</li>
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

<h3>ATCVER</h3>
<p>To request the version of this device.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA20-A_1V3&lt;CR&gt;&lt;LF&gt;</td>
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

<h2>3.UA20-E AT Commands</h2>
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
        <td>
            IN ATCD&lt;CR&gt;&lt;LF&gt;<br>
           <p>OUT ATCD 20.11, 23&lt;CR&gt;&lt;LF&gt;</p>
        </td>
        <td>
            To request the value of sensor data.<br>
            ATCD &lt;channel1&gt;,&lt;channel2&gt;<br>
            - &lt;ch1&gt; = user defined<br>
            - &lt;ch2&gt; = user defined<br>
        </td>
    </tr>
</table>



<h3>ATCMSTIDn (n=1~6)</h3>
<p>To request Modbus slave ID (1 ~ 247). The ID can also be disabled by setting it to 0.</p>
<table>
    <tr>
        <th>Channel</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>CH1</td>
        <td>IN ATCMSTID1 54&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMSTID1 54&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set Modbus slave ID for Channel 1.</td>
    </tr>
</table>


<h3>ATCMSTSTn (n=1~6)</h3>
<p>To request or set the Modbus slave start address for each channel.</p>
<table border="1">
    <tr>
        <th>Channel</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>CH1</td>
        <td>IN ATCMSTST1 1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMSTST1 1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set Modbus slave start address for Channel 1.</td>
    </tr>
    <tr>
        <td>CH2</td>
        <td>IN ATCMSTST2 2&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMSTST2 2&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set Modbus slave start address for Channel 2.</td>
    </tr>
</table>


<h3>ATCMSTCTn (n=1~6)</h3>
<p>To request or set Modbus slave channel type (float or int).</p>
<table border="1">
    <tr>
        <th>Channel</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>CH1</td>
        <td>IN ATCMSTCT1 2&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMSTCT1 2&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set Modbus slave channel type to float for Channel 1.</td>
    </tr>
    <tr>
        <td>CH2</td>
        <td>IN ATCMSTCT2 1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMSTCT2 1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set Modbus slave channel type to int(word) for Channel 2.</td>
    </tr>
</table>

<h3>ATCMSTCDn (n=1~6)</h3>
<p>To request or set Modbus slave channel type division (1, 10, 100, 1000).</p>
<table border="1">
    <tr>
        <th>Channel</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>CH1</td>
        <td>IN ATCMSTCD1 2&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMSTCD1 2&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set division to 100 for Channel 1.</td>
    </tr>
    <tr>
        <td>CH2</td>
        <td>IN ATCMSTCD2 3&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMSTCD2 3&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set division to 1000 for Channel 2.</td>
    </tr>
</table>

<h3>ATCMSTDLYn (n=1~6)</h3>
<p>To set Modbus communication delay (in milliseconds).</p>
<table border="1">
    <tr>
        <th>Channel</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>CH1</td>
        <td>IN ATCMSTDLY1 1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMSTDLY1 1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set communication delay to 0.5 seconds for Channel 1.</td>
    </tr>
    <tr>
        <td>CH2</td>
        <td>IN ATCMSTDLY2 3&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMSTDLY2 3&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set communication delay to 1.5 seconds for Channel 2.</td>
    </tr>
</table>

<h3>ATCMODSWn (n=1~6)</h3>
<p>To request or set Modbus slave float byte swap type (little-endian or big-endian).</p>
<table border="1">
    <tr>
        <th>Channel</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>CH1</td>
        <td>IN ATCMODSW1 0&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODSW1 0&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set byte swap to little-endian (default) for Channel 1.</td>
    </tr>
    <tr>
        <td>CH2</td>
        <td>IN ATCMODSW2 1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODSW2 1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set byte swap to big-endian for Channel 2.</td>
    </tr>
</table>

<h3>ATCMODBRn (n=1~6)</h3>
<p>To set Modbus baud rate.</p>
<table border="1">
    <tr>
        <th>Channel</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>CH1</td>
        <td>IN ATCMODBR1 1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODBR1 1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set baud rate to 9600 (default) for Channel 1.</td>
    </tr>
    <tr>
        <td>CH2</td>
        <td>IN ATCMODBR2 4&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODBR2 4&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set baud rate to 38400 for Channel 2.</td>
    </tr>
</table>

<h3>ATCMODTOn (n=1~6)</h3>
<p>To set Modbus timeout.</p>
<table border="1">
    <tr>
        <th>Channel</th>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>CH1</td>
        <td>IN ATCMODTOT1 0&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODTOT1 0&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set timeout to 1 second for Channel 1.</td>
    </tr>
    <tr>
        <td>CH2</td>
        <td>IN ATCMODTOT2 1&lt;CR&gt;&lt;LF&gt;<br>OUT ATCMODTOT2 1&lt;CR&gt;&lt;LF&gt;</td>
        <td>Set timeout to 0.15 seconds for Channel 2.</td>
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

<h3>ATCVER</h3>
<p>To request the version of this device.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>IN ATCVER&lt;CR&gt;&lt;LF&gt;<br>OUT ATCVER UA20-A_1V3&lt;CR&gt;&lt;LF&gt;</td>
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

