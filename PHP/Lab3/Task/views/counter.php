<?php
$counter = new Counter();
$counter->incrementAndUpdate();
$count = $counter->getCounter();
echo "<h1>counter: $count. </h1>";
?>