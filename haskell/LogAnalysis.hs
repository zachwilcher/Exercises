{-# OPTIONS_GHC -Wall #-}
module LogAnalysis where

import Log

parseMessage :: String -> LogMessage

parseMessage msg = case msg of
  ('I':(Int t):s) -> LogMessage Info t s
  ('W':(Int t):s) -> LogMessage Warning t s
  ('E':(Int e):(Int t):s) -> LogMessage (Error e) t s
  s -> LogMessage Unknown s

