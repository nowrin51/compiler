<?php

function shiftReduceParse($numProductions, $productions, $inputString) {
    // Parse productions
    $gram = [];
    for ($i = 0; $i < $numProductions; $i++) {
        list($nonTerminal, $productionRule) = explode('->', $productions[$i]);
        $gram[] = [trim($nonTerminal), trim($productionRule)];
    }

    // Initialize stack and input
    $stack = [];
    $input = str_split(trim($inputString));
    $len = count($input);
    $i = 0;
    $st_pos = 0;

    $stack[$st_pos] = $input[$i];
    $i++;
    $st_pos++;
    $output = "<table border='1'><tr><th>Stack</th><th>Input</th><th>Action</th></tr>";

    do {
        $r = 1;
        while ($r != 0) {
            $output .= "<tr><td>";
            for ($j = 0; $j < $st_pos; $j++) {
                $output .= $stack[$j];
            }
            $output .= "</td><td>";
            for ($j = $i; $j < $len; $j++) {
                $output .= $input[$j];
            }
            $output .= "</td><td>";
            if ($r == 2) {
                $output .= "Reduced";
            } else {
                $output .= "Shifted";
            }
            $output .= "</td></tr>";

            $r = 0;
            for ($j = 0; $j < $st_pos; $j++) {
                $ts = "";
                for ($k = $j; $k < $st_pos; $k++) {
                    $ts .= $stack[$k];
                }
                for ($k = 0; $k < $numProductions; $k++) {
                    if ($ts == $gram[$k][1]) {
                        for ($l = $j; $l < $st_pos; $l++) {
                            unset($stack[$l]);
                        }
                        $stack[$j] = $gram[$k][0];
                        $st_pos = $j + 1;
                        $r = 2;
                        break 2;
                    }
                }
            }
        }
        if ($i < $len) {
            $stack[$st_pos] = $input[$i];
            $i++;
            $st_pos++;
        }
    } while (count($stack) != 1 || $stack[0] != 'S' || $i != $len);

    if (count($stack) == 1 && $stack[0] == 'S' && $i == $len) {
        $output .= "<tr><td colspan='3'>Accepted</td></tr>";
    } else {
        $output .= "<tr><td colspan='3'>Not Accepted</td></tr>";
    }

    $output .= "</table>";
    return $output;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $numProductions = intval($_POST['numProductions']);
    $productions = explode("\n", trim($_POST['productions']));
    $inputString = $_POST['inputString'];

    echo "<h1>Shift-Reduce Parser Result</h1>";
    echo shiftReduceParse($numProductions, $productions, $inputString);
}
?>
