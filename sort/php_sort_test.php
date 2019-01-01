<?php

$array = [1,2,3,4,1,1,1,3,34,2,12,12,1,21,21,12,12,21,4,34,45,54,21,12];

uksort($array, function ($ak, $bk) use ($array) {
    $a = $array[$ak];
    $b = $array[$bk];
    return $a > $b;
});

foreach($array as $v) {
    echo $v, ' ';
}
