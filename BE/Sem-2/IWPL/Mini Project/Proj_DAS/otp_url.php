
<?php
// create a new cURL resource
$ch = curl_init();

// set URL and other appropriate options
curl_setopt($ch, CURLOPT_URL, "http://cloud.smsindiahub.in/vendorsms/pushsms.aspx?user=KNEOAutomation&password=kneomapp123&msisdn=918446915553&sid=KNMAPP&msg=EVENT%20Dear%20Diksha,%20your%20OTP%20is%20123456.&fl=0&gwid=2");
curl_setopt($ch, CURLOPT_HEADER, 0);

// grab URL and pass it to the browser
curl_exec($ch);

// close cURL resource, and free up system resources
curl_close($ch);


?>
