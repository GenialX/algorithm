<?php

$a = [1,2,3,4,1,1,1,3,34,2,12,12,1,21,21,12,12,21,4,34,45,54,21,12];

// version wikipedia
function quick_sort_recursive_v1(array &$a, int $start, int $end) {
    // boundary
    if ($start >= $end) {
        return;
    }
    // find the pivot
    $left = $start;
    $right = $end - 1;
    $middle = $end;
    while ($left < $right) {
        while ($left < $right && $a[$left] < $a[$middle]) {
            ++$left;
        }
        while ($left < $right && $a[$right] >= $a[$middle]) {
            --$right;
        }
        swap($a, $left, $right);
    }
    if ($a[$left] >= $a[$middle]) {
        swap($a, $left, $middle);
    } else {
        $left++;
    }

    // sort
    quick_sort_recursive_v1($a, $start, $left - 1);
    quick_sort_recursive_v1($a, $left + 1, $end);
}

// version easy mind
function quick_sort_recursive_v2(array &$a, int $start, int $end) {
    // boundary
    if ($start >= $end) {
        return;
    }

    // partition
    $pivot = partition($a, $start, $end);

    // sort(divide and conquer)
    quick_sort_recursive_v2($a, $start, $pivot - 1);
    quick_sort_recursive_v2($a, $pivot + 1, $end);
}

function partition(array &$a, $start, $end) {
    $middle = $a[$end];
    $pivot = 0;
    for ($i = 0; $i < $end; ++$i) {
        if ($a[$i] <= $middle) {
            swap($a, $i, $pivot++);
        }
    }
    swap($a, $pivot, $end);
    return $pivot;
}

function swap(array &$a, int $i, int $j) {
    $t = $a[$i];
    $a[$i] = $a[$j];
    $a[$j] = $t;
}

//echo sizeof($a); 
quick_sort_recursive_v2($a, 0, sizeof($a) - 1);
foreach($a as $v) {
    echo $v, ' ';
}
