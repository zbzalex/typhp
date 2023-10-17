<?php

include __DIR__ . "/vendor/autoload.php";

final class Main
{
    public static function main(
        mixed $argc,
        mixed $args = []
    ): int {
        echo sprintf("count args = %d", $args);

        return 0;
    }
}
