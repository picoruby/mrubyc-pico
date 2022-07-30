class PWM

  def initialize(pin)
    @pin = pin
    pwm_init( @pin )
  end

  def freq( freq )
    pwm_set_freq( @pin, freq )
  end

  def duty( duty )
    pwm_set_duty( @pin, duty )
  end

  def deinit
    pwm_set_duty( @pin, 0 )
  end

end
