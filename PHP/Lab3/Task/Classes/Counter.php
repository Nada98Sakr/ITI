<?php
class Counter implements CounterInterface{
    private $_counter;
    public function __construct (){
        $this->_counter = $this->getCounter();
    }

    public function getCounter(){
        if(file_exists(_COUNTER_FILE_)){
            return intval(file_get_contents(_COUNTER_FILE_));
        }else{
            return 0;
        }
    }

    public function increment(){
        if(! isset($_SESSION[_SESSION_COUNTER])){
            $this->_counter++;
            $_SESSION[_SESSION_COUNTER] = true;
            return $this->_counter++;
        }else{
            return false;
        }
    }

    public function update(){
        $fp = fopen(_COUNTER_FILE_, 'w+');
        fwrite($fp, $this->_counter);
        fclose($fp);
    }

    public function incrementAndUpdate(){
        if($this->increment() != false){
            $this->update();
        }
    }
}

?>