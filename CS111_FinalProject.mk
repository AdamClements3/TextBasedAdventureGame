##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CS111_FinalProject
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics
ProjectPath            :=C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject
IntermediateDirectory  :=../build-$(ConfigurationName)/CS111_FinalProject
OutDir                 :=../build-$(ConfigurationName)/CS111_FinalProject
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Accelerate
Date                   :=13/12/2020
CodeLitePath           :=C:/Users/Accelerate/Documents/CodeLite
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)GLEW_STATIC $(PreprocessorSwitch)STB_IMAGE_IMPLEMENTATION 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  -mwindows -mconsole
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(ProjectPath)/Dependencies/GLFW/include $(IncludeSwitch)$(ProjectPath)/Dependencies/GLEW/include $(IncludeSwitch)$(ProjectPath)/Dependencies/stb_image/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)glew32 $(LibrarySwitch)glfw3 $(LibrarySwitch)opengl32 
ArLibs                 :=  "glew32" "glfw3" "opengl32" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(ProjectPath)/Dependencies/GLEW/lib $(LibraryPathSwitch)$(ProjectPath)/Dependencies/GLFW/lib-mingw-w64 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Users\Accelerate\Documents\CodeLite
Objects0=../build-$(ConfigurationName)/CS111_FinalProject/Shader.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CS111_FinalProject/VertexArray.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CS111_FinalProject/Texture.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CS111_FinalProject/Item.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CS111_FinalProject/Renderer.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CS111_FinalProject/Enemy.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CS111_FinalProject/Main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CS111_FinalProject/Maze.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CS111_FinalProject/Player.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CS111_FinalProject/Parser.cpp$(ObjectSuffix) \
	../build-$(ConfigurationName)/CS111_FinalProject/Room.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/CS111_FinalProject/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\CS111_FinalProject" mkdir "..\build-$(ConfigurationName)\CS111_FinalProject"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\CS111_FinalProject" mkdir "..\build-$(ConfigurationName)\CS111_FinalProject"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/CS111_FinalProject/.d:
	@if not exist "..\build-$(ConfigurationName)\CS111_FinalProject" mkdir "..\build-$(ConfigurationName)\CS111_FinalProject"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/CS111_FinalProject/Shader.cpp$(ObjectSuffix): Shader.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Shader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Shader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Shader.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Shader.cpp$(DependSuffix): Shader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Shader.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Shader.cpp$(DependSuffix) -MM Shader.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Shader.cpp$(PreprocessSuffix): Shader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Shader.cpp$(PreprocessSuffix) Shader.cpp

../build-$(ConfigurationName)/CS111_FinalProject/VertexArray.cpp$(ObjectSuffix): VertexArray.cpp ../build-$(ConfigurationName)/CS111_FinalProject/VertexArray.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/VertexArray.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/VertexArray.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/VertexArray.cpp$(DependSuffix): VertexArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/VertexArray.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/VertexArray.cpp$(DependSuffix) -MM VertexArray.cpp

../build-$(ConfigurationName)/CS111_FinalProject/VertexArray.cpp$(PreprocessSuffix): VertexArray.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/VertexArray.cpp$(PreprocessSuffix) VertexArray.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Texture.cpp$(ObjectSuffix): Texture.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Texture.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Texture.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Texture.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Texture.cpp$(DependSuffix): Texture.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Texture.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Texture.cpp$(DependSuffix) -MM Texture.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Texture.cpp$(PreprocessSuffix): Texture.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Texture.cpp$(PreprocessSuffix) Texture.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Item.cpp$(ObjectSuffix): Item.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Item.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Item.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Item.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Item.cpp$(DependSuffix): Item.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Item.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Item.cpp$(DependSuffix) -MM Item.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Item.cpp$(PreprocessSuffix): Item.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Item.cpp$(PreprocessSuffix) Item.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Renderer.cpp$(ObjectSuffix): Renderer.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Renderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Renderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Renderer.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Renderer.cpp$(DependSuffix): Renderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Renderer.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Renderer.cpp$(DependSuffix) -MM Renderer.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Renderer.cpp$(PreprocessSuffix): Renderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Renderer.cpp$(PreprocessSuffix) Renderer.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Enemy.cpp$(ObjectSuffix): Enemy.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Enemy.cpp$(DependSuffix): Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Enemy.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Enemy.cpp$(DependSuffix) -MM Enemy.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Enemy.cpp$(PreprocessSuffix): Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Enemy.cpp$(PreprocessSuffix) Enemy.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Main.cpp$(ObjectSuffix): Main.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Main.cpp$(DependSuffix): Main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Main.cpp$(DependSuffix) -MM Main.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Main.cpp$(PreprocessSuffix): Main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Main.cpp$(PreprocessSuffix) Main.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Maze.cpp$(ObjectSuffix): Maze.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Maze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Maze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Maze.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Maze.cpp$(DependSuffix): Maze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Maze.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Maze.cpp$(DependSuffix) -MM Maze.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Maze.cpp$(PreprocessSuffix): Maze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Maze.cpp$(PreprocessSuffix) Maze.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Player.cpp$(ObjectSuffix): Player.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Player.cpp$(DependSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Player.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Player.cpp$(DependSuffix) -MM Player.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Player.cpp$(PreprocessSuffix): Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Player.cpp$(PreprocessSuffix) Player.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Parser.cpp$(ObjectSuffix): Parser.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Parser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Parser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Parser.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Parser.cpp$(DependSuffix): Parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Parser.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Parser.cpp$(DependSuffix) -MM Parser.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Parser.cpp$(PreprocessSuffix): Parser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Parser.cpp$(PreprocessSuffix) Parser.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Room.cpp$(ObjectSuffix): Room.cpp ../build-$(ConfigurationName)/CS111_FinalProject/Room.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Accelerate/Downloads/ForFermin/CS111_FinalProject-graphics-20201212T202013Z-001/CS111_FinalProject-graphics/CS111_FinalProject/Room.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Room.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CS111_FinalProject/Room.cpp$(DependSuffix): Room.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CS111_FinalProject/Room.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CS111_FinalProject/Room.cpp$(DependSuffix) -MM Room.cpp

../build-$(ConfigurationName)/CS111_FinalProject/Room.cpp$(PreprocessSuffix): Room.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CS111_FinalProject/Room.cpp$(PreprocessSuffix) Room.cpp


-include ../build-$(ConfigurationName)/CS111_FinalProject//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


