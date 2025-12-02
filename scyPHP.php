<?php
echo "Hello World\n";

interface FunctionList {};

class PHPWorkSpace implements FunctionList
{


    public array $combinArray;
    public int $combinResult;

    public array $robotResult;

    function __construct(array $globalArray)
    {
        $this->combinArray = $globalArray['combinArray'];
        $this->combinResult = 1;
    }

    function combination(): int
    {
        foreach ($this->combinArray as $c) {
            $this->combinResult *= $c;
        }
        echo $this->combinResult, "\n";
        return $this->combinResult;
    }

    function robotTrack($n = 0, $w = 0, $s = 0, $e = 0): array
    {
        $l = $n + ($s * -1);
        $r = $w + ($e * -1);

        $this->robotResult = array($l, $r);
        // array_push($this->robotResult, $l, $r);

        print_r($this->robotResult);
        return $this->robotResult;
    }

    function is_palindrome($s): bool
    {
        // $r = str_replace('/\w+/ig', ' ', strtolower($s));
        $r = str_replace('/^[a-zA-Z0-9]+$/', ' ', strtolower($s));
        // $r = var_dump(filter_var(strtoLower($s), FILTER_SANITIZE_SPECIAL_CHARS));
        // $r = filter_var(strtoLower($s), FILTER_VALIDATE_REGEXP, array("options" => array("regexp" => "/[a-zA-Z0-9]+$/")));
        // $r = preg_match('/^[a-zA-Z0-9]+$/', strtolower($s));
        $r = preg_replace("/[^a-zA-Z0-9]/", "", strtolower($s));
        return $r == strrev($r);
    }

    function findMaxAverage($nums, $k)
    {
        $i = $m = 0;
        $j = $k;

        array_values($nums);

        while ($j < count($nums)) {

            $sum = 0;
            // $sum = array_sum(array_slice($nums, $i, $j));
            // $m = max($m, $sum);
            for ($i = 0; $i < $j; $i++) {
                $sum += $nums[$i];
            }

            $m = max($m, $sum);

            $j++;

            // print("Max " . max($m, array_sum(array_slice($nums, $i, $j))));
        }
        return $m / $k;
    }

    function mergeAlternately($word1, $word2)
    {
        $arr1 = explode(' ', $word1);
        $arr2 = array($word2);
        $arr3 = [];

        for ($i = 0, $j = 0, $k = 0; $i < max(strlen($word1), strlen($word2)); $i++) {
            if ($k < count($arr1)) {
                array_push($arr3, $arr1[$k++]);
            }

            if ($j < count($arr2)) {
                array_push($arr3, $arr2[$j++]);
            }
        }
        print(implode("", $arr3));
        return implode("", $arr3);
    }
}

$globalArray = array("combinArray" => [2, 3, 4, 5]);

$phpWorkSpace = new PHPWorkSpace($globalArray);
$phpWorkSpace->combination();
$phpWorkSpace->robotTrack(-10, 20, 10);
$phpWorkSpace->is_palindrome("A man, a plan, a canal: Panama");
$phpWorkSpace->findMaxAverage([1, 12, -5, -6, 50, 3], 4);
$phpWorkSpace->mergeAlternately("abc", "pqr");
