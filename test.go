// package main

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
  // file, err := os.Open("file")
  // if err != nil {
    // log.Fatalf("Error open file: %v", err)
  // }
  // defer file.Close()
  // bytesRead := make([]byte, 33)
// 
  // n, err := file.Read(bytesRead)
  // if err != nil {
    // log.Fatalf("error reading from file: %v", err)
  // }
  // log.Printf("We read \"%s\" into bytesRead (%d bytes)", string(bytesRead), n)

  ReaderFile("file")
  r := some(10, 8)
  log.Printf("\n%d\n", r)
  fmt.Println("Hello")
}