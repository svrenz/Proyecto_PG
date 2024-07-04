<!-- Haeding -->

<a id="readme-top"></a>
<!-- PROJECT LOGO -->
<br />

<div align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="images/virtualmarket.jpg" alt="Logo" width="410" height="200">
  </a>

  <h3 align="center">Exploring the SuperMarket 🛒</h3>

  <p align="center">
    <em>An immersive walk through the supermarket!</em>
    <br />
    <hr>
    <a href="https://github.com/svrenz/Proyecto_PG"><strong>Explore the docs »</strong></a>
    <hr>
    <a href="https://github.com/svrenz/Proyecto_PG/graphs/contributors"><strong>Explore contributors »</strong></a>
    <hr>
    <br />
  </p>
</div>
<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
# About The Project

 <img src="images/WhatsApp Image 2024-07-03 at 9.29.24 PM.jpeg">

The Virtual Supermarket Tour is an interactive app we developed using OpenGL. This innovative application provides you with an immersive shopping experience in a realistic 3D environment.

Explore the virtual environment of a supermarket filled with various 3D models of items you'd find in a real supermarket, such as refrigerators stocked with different products. Music sounds and an identical layout to a real market further enhance the realism of the experience.

Wander through the aisles lined with shelves stocked with products virtually. Developed using OpenGL technology, Virtual Supermarket allows you to:
<em>
*  Use the <strong>WASD</strong> keys to move around the supermarket at your own pace.
* Get closer to the shelves to view products up close using the <strong>mouse.</strong>
</em>



<p align="right">(<a href="#readme-top">back to top</a>)</p>

#  Getting Started
❗`This project only works for Visual Studio 2022 x64`❗
### Running the app
To run the Virtual Supermarket Tour application, follow these steps:

* <strong>Download the project:</strong> Download the  
``` sh
  Proyecto_PG.zip
  ``` 
  file and extract it to a location of your choice.
  * <strong>Open the project:</strong> Once the files are extracted, navigate to the extracted folder and open the file named 
  ```sh 
  Proyecto_PG.sln
  ``` 
  This will launch the CodeBlocks IDE and automatically load the project.
  * <strong>Build and run the application: </strong>Once the project is loaded in CodeBlocks, click the <em><strong> "Build" </strong></em> button to compile the application. Once the build is successful, click the "Run" button to launch the Supermarket Tour application.

  Note: There is no need to move or modify any files within the extracted folder. The project is configured to run directly from the extracted location.

## Screenshots
<img src="images/Captura de pantalla (17).png">
<hr>
<img src="images/WhatsApp Image 2024-07-03 at 9.29.19 PM.jpeg">
<hr>
<img src="images/WhatsApp Image 2024-07-03 at 9.29.20 PM.jpeg">
<hr>
<img src="images/WhatsApp Image 2024-07-03 at 9.29.22 PM.jpeg">

## Creation 

<em>The Virtual Supermarket application was developed using Visual Studio Community, C++, and OpenGL.</em>

 The project was configured in VS to recognize dependencies and establish relative paths. The project structure `includes 9 header files (.h) and 2 source code files (.cpp).`
 
 <strong> Header files </strong> define classes and functions to handle buffers, arrays, shaders, textures, cameras, meshes, and graphics methods. <strong>Source code files</strong> provide access to the stb.h library and contain the main program logic, including window creation, calls to methods for creating primitives and texture objects, shader loading, scene rendering, texture application, model and projection matrix modification, and resource cleanup upon termination. The program creates a window and sets up a 3D camera, loads 3D objects such as meshes into the scene, applies textures to enhance realism, uses a while loop to update the scene and respond to user input, modifies model and projection matrices for each object and renders them in the scene, and finally cleans up the resources used upon termination.
 
  The development of the application involved the integration of tools and resources to create a realistic and interactive 3D environment, resulting in an engaging and attractive virtual shopping experience.

## Documentation 🧑‍💻

* <a href="https://learnopengl.com/"><strong>LearnOpenGL</strong></a>

## Built With ⚙️

- [C++](https://isocpp.org/) - iostream, sstream, fstream, vector, string, Windows.h, 
- [OpenGL](https://www.opengl.org/) - OpenGL
  - [GLFW](https://www.glfw.org/) - GLFW
  - [GLAD](https://github.com/Dav1dde/glad) - GLAD
  - [Assimp](https://github.com/assimp/assimp) - Importer.hpp, scene.h, postprocess.h
  - [STB_Image](https://github.com/nothings/stb) - STB_Image
  - [GLM](https://glm.g-truc.net/0.9.9/index.html) - GLM, matrix_transform.hpp, type_ptr.hpp
- [ShaderClass.h](https://learnopengl.com/Getting-started/Shaders) - Shader
- [Camera.h](https://learnopengl.com/Getting-started/Camera) - Camera
- [Model.h](https://learnopengl.com/Model-Loading/Model) - Model
- [Mesh.h](https://learnopengl.com/Model-Loading/Mesh) - Mesh




<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Authors

* <a href="https://github.com/Manu-1118"><strong></strong>Tijerino Manuel</strong></a>
* <a href="https://github.com/svrenz"><strong></strong>López Dania</strong></a>
* <a href="https://github.com/cruzroger11"><strong></strong>Cruz Roger</strong></a>

<br>

🙅‍♂️🙅🙅‍♀️

❗`Exploring the SuperMarket application is intended for educational purposes only. It was created as part of a university project, and the developers assume no responsibility for any loss or damage that may arise from its use.`❗

#### You can see how it works with the following button
[![Demo Out of the Woods](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/watch?v=WjlISaPDcpM)
