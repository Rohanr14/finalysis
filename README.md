# Finalysis

## Overview

This project aims to provide a comprehensive real-time financial data analysis tool that not only processes market data but also incorporates sentiment analysis from social media and news feeds, advanced prediction models, interactive visualizations, and real-time risk assessment. The tool leverages parallel computing for high-performance processing and offers unique insights by combining traditional financial data with alternative data sources.

## Key Features
1. **Real-time Market Data Fetching**: Uses APIs like Alpha Vantage to fetch market data.
2. **Sentiment Analysis Integration**: Analyzes sentiment from social media platforms to gauge market sentiment.
3. **Advanced Prediction Models**: Implements advanced models for more accurate market predictions.
4. **Interactive Visualizations**: Provides dynamic and interactive visualizations using web technologies.
5. **Real-time Risk Assessment**: Provides real-time risk metrics and alerts based on market data and sentiment analysis.
6. **User Customization**: Allows users to customize their analysis parameters and uses AI to provide personalized insights.

## Project Structure
```
finalysis/
├── CMakeLists.txt
├── src/
│ ├── main.cpp
│ ├── data_fetcher.cpp
│ ├── data_fetcher.h
│ ├── data_processor.cpp
│ ├── data_processor.h
│ ├── sentiment_analyzer.cpp
│ ├── sentiment_analyzer.h
│ ├── trend_analyzer.cpp
│ ├── trend_analyzer.h
│ ├── risk_assessor.cpp
│ ├── risk_assessor.h
│ └── visualizer.cpp
│ └── visualizer.h
└── include/
├── json/
│ └── json.h (header-only JSON library)
└── dlib/
└── dlib headers (if using dlib for machine learning)
└── curl/
└── curl headers
```

## Prerequisites

- C++ Compiler (g++ or equivalent)
- CMake
- Libraries: libcurl, JSON for Modern C++, Dlib (for machine learning), OpenMP
- API keys for financial and sentiment data (e.g., Alpha Vantage, Twitter API)

## Setup Instructions

1. **Clone the repository and navigate to the project directory:**
    ```sh
    git clone https://github.com/Rohanr14/finalysis/
    cd finalysis
    ```

2. **Create a build directory and navigate to it:**
    ```sh
    mkdir build
    cd build
    ```

3. **Run CMake to generate build files:**
    ```sh
    cmake ..
    ```

4. **Build the project:**
    ```sh
    make
    ```

5. **Run the executable:**
    ```sh
    ./Finalysis
    ```

## Configuration

Update the `main.cpp` file with your API keys (it is recommended you store them in your env variables):
```cpp
int main() {
    const char* alphaVantageApiKey = getenv("ALPHA_VANTAGE_API_KEY");
    const char* twitterApiKey = getenv("TWITTER_API_KEY");
    const char* twitterApiSecretKey = getenv("TWITTER_API_SECRET_KEY");
    string symbol = "AAPL";
...
}
```

## Dependencies
Make sure to install the required dependencies before building the project:
```sh
sudo apt-get update
sudo apt-get install g++ cmake libcurl4-openssl-dev libjsoncpp-dev
For additional libraries like Dlib, you can follow their respective installation guides.
```

## Usage
After running the executable, the tool will fetch real-time market data and sentiment data, process it, analyze trends, assess risk, and visualize the results. Adjust parameters in the source code to customize the analysis according to your needs.

## Contributing
Feel free to fork this repository, make enhancements, and create pull requests. Contributions are welcome!

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments
Alpha Vantage
Dlib
libcurl
JSON for Modern C++

## Contact
For any questions or feedback, please contact [glitch.berths0n@icloud.com].
