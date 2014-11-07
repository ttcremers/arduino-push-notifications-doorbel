require 'rubygems'
require 'serialport'
require 'pushover'

ser = SerialPort.new "/dev/tty.usbmodem1411", 9600

puts "Listening for the doorbel..."
while (true) do
  bel = ser.readline
  puts "got: #{bel}"
  if ( bel != "" )
    Pushover.notification( message: 'DING DONG!!', 
                          title: "DoorBell",
                         user: 'some-user',
                         token: 'some-token')
  end
  sleep(1)
end
