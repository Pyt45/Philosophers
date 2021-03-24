package main

import (
  "log"
  "os"
  "fmt"
)

func ReaderFile(name string) {
  file, err := os.Open(name)

  if err != nil {
    log.Fatalf("Error open file : %v", err)
  }
  defer file.Close()
  bytesRead := make([]byte, 33)

  n, err := file.Read(bytesRead)

  if err != nil {
    log.Fatalf("Error reading from file : %v", err)
  }
  log.Printf("%s => %d", string(bytesRead), n)
}

func some(x int, y int) int {
  return x + y
}

func main() {

  // ReaderFile("file")
  // r := some(10, 8)
  // log.Printf("\n%d\n", r)
  // fmt.Println("Hello")

  for _, line := range os.Args[1:] {
    fmt.Printf("%s\n", line)
  }
  log.Println("End");
  path, err := os.Getwd();
  if err != nil {
    log.Fatalf("Can't get pwd %v", err)
  }
  fmt.Printf("pwd = %s\n", path);
}

// import (
//     "io"
//     "log"
//     "net/http"
//     "os"
// )

// func main() {
//     // Make HTTP GET request
//     response, err := http.Get("https://www.devdungeon.com/")
//     if err != nil {
//         log.Fatal(err)
//     }
//     defer response.Body.Close()

//     // Copy data from the response to standard output
//     n, err := io.Copy(os.Stdout, response.Body)
//     if err != nil {
//         log.Fatal(err)
//     }

//     log.Println("Number of bytes copied to STDOUT:", n)
// }