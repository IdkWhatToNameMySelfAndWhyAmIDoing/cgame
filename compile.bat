C:\VulkanSDK\1.4.313.0\Bin\glslc.exe shaders\simple_shader.vert -o shaders\simple_shader.vert.spv
C:\VulkanSDK\1.4.313.0\Bin\glslc.exe shaders\simple_shader.frag -o shaders\simple_shader.frag.spv
g++ *.cpp -o main -lvulkan-1 -llibglfw3 *.hpp
main.exe
pause