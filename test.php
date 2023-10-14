<?php

// typhp/List.php
namespace typhp {
    class List<T> {
        public function __construct() {
        }
    }

    class Caller {
        public static function call(((int) => void) $func, List<mixed> $args) {
            call_user_func_array($func, $args);
        }
    }
}

class WebApplication extends \Hill\IApplication {

    private string | int | \Exception $name_or_class;

    public function __construct(
        private mixed $name,
    ) {

    }

    public static function main(int $argc, \typhp\List<string> $argv = []) {

        (() ==> { echo "hello"; })();

        \typhp\Caller::call(( int $num ) ==> {
            echo $num;
        }, [
            1
        ]);
    }
}