# coding: utf-8
class ADC

  def initialize(pin)
    channelAll = {
      "GPIO26" => 0, "GPIO27" => 1, "GPIO28" => 2, "GPIO29" => 3
    }

    channel = channelAll["GPIO#{pin}"]
    adc_init(channel)
  end

  def read()
    #チャンネルの設定不要．1 つしか扱えないらしい.    
    return adc_read()
  end

end
