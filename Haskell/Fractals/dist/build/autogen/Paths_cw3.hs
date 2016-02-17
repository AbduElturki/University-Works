module Paths_cw3 (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/abdu/Copy/Programming/Haskell/Fractals/.cabal-sandbox/bin"
libdir     = "/home/abdu/Copy/Programming/Haskell/Fractals/.cabal-sandbox/lib/x86_64-linux-ghc-7.10.2.20151118/cw3-0.1.0.0-BJCZ1r8ri4R3tlC5u7SfYf"
datadir    = "/home/abdu/Copy/Programming/Haskell/Fractals/.cabal-sandbox/share/x86_64-linux-ghc-7.10.2.20151118/cw3-0.1.0.0"
libexecdir = "/home/abdu/Copy/Programming/Haskell/Fractals/.cabal-sandbox/libexec"
sysconfdir = "/home/abdu/Copy/Programming/Haskell/Fractals/.cabal-sandbox/etc"

getBinDir, getLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "cw3_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "cw3_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "cw3_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "cw3_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "cw3_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
