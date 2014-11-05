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
                         user: 'Ie9D09nl8JntKD0NfKFr1lmack3s2n',
                         token: 'TnbTpcKeDsrgxWeDq6eZyUBqh8HQys')
  end
  sleep(1)
end
