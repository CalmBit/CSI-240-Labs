#ifndef CRYPTO_ENGINE_H
#define CRYPTO_ENGINE_H

//begin Ethan Brooks

// MAX_LINE_COUNT
//   Sets the maximum number of lines that the
//   the crypto-engine interface is set to
//   handle. Acts as an initial size for line array
#define MAX_LINE_COUNT 128

class CryptoEngine
{
protected:
  
  // std::string token;
  //   Defines a set of rules for the crypto-engine
  //   to interpret upon processing -- operations to
  //   undertake on plaintext to produce ciphertext.
  std::string token;

  std::string[] lines = std::string[MAX_LINE_COUNT]; 
  
public:
  
  // virtual void outputToFile(std::string file);
  //   Pipes ciphertext/plaintext to file.
  virtual void outputToFile(std::string file) = 0;

  // virtual void outputToStdout();
  //   Pipes ciphertext/plaintext to standard
  //   output.
  virtual void outputToStdout() = 0;

  // virtual void processFile();
  //   Takes input from file and processes it
  //   according to the rules set down in the
  //   token string.
  virtual void processFile(std::string file) = 0;

  // virtual void processString();
  //  Takes input from a string and processes
  //  it according to the rules set down in
  //  the token string.
  virtual void processString(std::string string) = 0;
  
};
//end Ethan Brooks
#endif
