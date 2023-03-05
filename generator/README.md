<h1>
    <div align="center">
        <img alt="Generator" src=".github/generator/cgeneretor.png" width="700" >
    </div>
</h1>

This program is meant to be used as a complement to the Engine program. The .3d files are generated here and included in scenes that should be passed as argument to the Engine.

## 🚀 Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

```
bin/setup
```

**You may also need to give the bin folder permission to run the scripts.**

```
sudo chmod 755 bin/*
```

## 🔨 Development

Here you can find some scripts that will make your life easier.

- Compile and run the program.

```
bin/run <args>
```

- Build the target.

```
bin/build
```

- Format the code.

```
bin/format
```

- Clean the project directory.

```
bin/clean
```

## 🏃‍♂️ Generate 3d files

- Sphere

```
bin/run sphere sphere <radius> <slices> <stacks> <file>.3d
```

- Box

```
bin/run box <length> <grid> <file>.3d
```

- Cone

```
bin/run cone <radius> <height> <slices> <stacks> <file>.3d
```

- Plane

```
bin/run plane <length> <divisions> <file>.3d
```
