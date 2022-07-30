
=begin
pin18 = Pin.new(18, Pin::IN)
adc = ADC.new(26) #Rotary Angle Sensor
pwm1 = PWM.new(25)

i = 0

while true
  puts (i * 100) % 1024 
  pwm1.duty( (i * 100) % 1024 )

  puts "Button : #{pin18.read}"
  puts "ADC    : #{adc.read}"
  
  sleep( 2 )
  i += 1
end
=end
=begin
#pin16 = Pin.new(16, Pin::OUT)
pin18 = Pin.new(18, Pin::IN)
pin25 = GPIO.new(25, Pin::OUT)

#adc = OnboardADC.new  #onboard Temp.
adc = ADC.new(26) #Rotary Angle Sensor

while true
  puts "Button : #{pin18.read}"
  puts "ADC    : #{adc.read}"
  
#  pin16.on
  pin25.on

  sleep( 2 )

#  pin16.off
  pin25.off
  sleep( 1 )
end
=end

#=begin
pin25 = GPIO.new(25, Pin::OUT)
adc = OnboardADC.new  #onboard Temp.

while true
  puts "ADC    : #{adc.read}"
  pin25.on
  sleep( 2 )
  pin25.off
  sleep( 1 )
end
#=end

