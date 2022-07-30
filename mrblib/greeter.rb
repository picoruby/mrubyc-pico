class Greeter

  def hello
    puts "Hello World! by mruby/c"
  end
  
  def write(value)
    unless(value == 0 || value == 1)
      puts "invalid value detected"
      return
    end
#    gpio_set_level(@pin, value)
    puts "write #{value}"
  end

end
