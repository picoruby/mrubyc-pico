class GPIO

  OUT = 0
  IN  = 1
  
  def initialize(pin, mode)
    @pin = pin
    if mode == GPIO::OUT
      gpio_mode_output(@pin)
    elsif mode == GPIO::IN
      gpio_mode_input(@pin)
    end
  end
  
  def write(value)
    unless(value == 0 || value == 1)
      puts "invalid value detected"
      return
    end
    gpio_set_level(@pin, value)
    puts "write #{value} (pin)"
  end

  def on
    write(1)
  end

  def off
    write(0)
  end

  def read
    gpio_get_level(@pin)
  end

  def value
    gpio_get_level(@pin)
  end

end
