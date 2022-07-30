# coding: utf-8
class OnboardADC

  def initialize()
    @channel = 4 
    adc_onboard_init(@channel)
  end

  def read()
    #チャンネルの設定不要．1 つしか扱えないらしい.    
    return adc_onboard_read()
  end

end
