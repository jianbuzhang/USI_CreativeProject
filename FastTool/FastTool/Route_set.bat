chcp 437
set IP_PRE=10.5
for /f "delims=: tokens=2" %%i in ('ipconfig ^| find "Default Gateway" ^| find "%IP_PRE%"') do set Gateway=%%i

echo Delete all the 0.0.0.0 route which include the new add wifi AP(192.168.1.1)
route delete 0.0.0.0
echo Add the 0.0.0.0 route which only include the orignal one(10.5.23.254)
route ADD 0.0.0.0 MASK 0.0.0.0 %Gateway% METRIC 3

