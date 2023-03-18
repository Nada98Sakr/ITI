<?php

namespace App\View\Components;

use Closure;
use Illuminate\Contracts\View\View;
use Illuminate\View\Component;

class Button extends Component
{
    public function __construct(public String $type, public String $label, public String $href)
    {
    }

    /*
     * Get the view / contents that represent the component.
     */
    public function render(): View|Closure|string
    {
        return <<<blade
            <a href={$this->href} class='btn btn-{$this->type}'>
                {$this->label}
            </a>
            blade;
    }
}
