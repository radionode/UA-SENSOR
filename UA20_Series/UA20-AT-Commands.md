
<img src="https://github.com/user-attachments/assets/771264bf-60dc-46db-bd62-2f0d790b0e11" width="40%" height="30%">

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
        UA20-A:  4-20mA Input  2CH<br>
        UA20-B:  4-20mA Input 1 CH with 12V output 1CH<br>
        UA20-C:  0~1V Input  2CH<br>
        UA20-D:  Pulse Input<br> 
        UA20-E:  1~6 Device Digital Input
        </td>
        <td>Signal Converter</td>
    </tr>
</table>

<h2>2. UA20 Series AT Commands</h2>
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
            <strong>*D model</strong><br>
            IN ATCD&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCD 0&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCD 1&lt;CR&gt;&lt;LF&gt;:
        </td>
        <td>
            To request the value of sensor data.<br>
            ATCD &lt;channel1&gt;,&lt;channel2&gt;<br>
            - &lt;ch1&gt; = user defined<br>
            - &lt;ch2&gt; = user defined<br>
            <li style="font-size: smaller;"><strong>D model:</strong> &lt;ch1&gt; = Pulse Count</li>
        </td>
    </tr>
</table>

<h3>ATCH</h3>
<p>To request the value of sensor data (Six channels),This mode is currently supported only for the UA20E.</p>
<table>
    <tr>
        <th>Example</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>
            IN ATCH&lt;CR&gt;&lt;LF&gt;<br>
            OUT ATCH 12.5, 13, 156, 12.3, 25, 56.5<&lt;CR&gt;&lt;LF&gt;<br>
        </td>
        <td>
            To request the value of sensor data.<br>
            ATCH &lt;channel1&gt;,&lt;channel2&gt;channel3&gt;channel4&gt;channel5&gt;channel6&gt;<br>
            - &lt;ch1&gt; = user defined<br>
            - &lt;ch2&gt; = user defined<br>
            - &lt;ch3&gt; = user defined<br>
            - &lt;ch4&gt; = user defined<br>
            - &lt;ch5&gt; = user defined<br>
            - &lt;ch6&gt; = user defined<br>
         
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
