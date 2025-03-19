# fract-ol

fract-ol is a graphics programming project developed as part of the 42 curriculum. It generates and visualizes fractals using the MinilibX graphics library, allowing users to explore famous mathematical sets such as the Mandelbrot and Julia sets.

## Features
- Interactive fractal visualization
- Supports Mandelbrot and Julia sets
- Zoom and movement controls
- Adjustable iterations for precision
- Color customization (optional enhancement)

## Installation
### Prerequisites
Ensure you have the following dependencies installed:
- A Unix-based system (Linux or macOS)
- `make` and `gcc`
- `mlx` (MinilibX graphics library)

### Clone the repository
```sh
git clone https://github.com/bou1337/fract-ol.git
cd fract-ol
```

### Build the project
```sh
make
```

## Usage
Run the program with:
```sh
./fractol mandelbrot
./fractol julia <real> <imaginary>
```

### Controls
- `Arrow Keys` - Move around the fractal
- `+ / -` - Increase/decrease iterations
- `Scroll` - Zoom in and out
- `ESC` - Exit the program

## Examples
To view the Mandelbrot set:
```sh
./fractol mandelbrot
```
To view the Julia set with specific parameters:
```sh
./fractol julia -0.7 0.27015
```

## Resources
- [42's fract-ol Subject](https://cdn.intra.42.fr/pdf/pdf/28536/en.subject.pdf) - Official project specifications.
- [Mandelbrot Set Explanation](https://en.wikipedia.org/wiki/Mandelbrot_set) - Mathematical background.
- [Julia Set Explanation](https://en.wikipedia.org/wiki/Julia_set) - Mathematical background.
