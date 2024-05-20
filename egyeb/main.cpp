// RANDOM FUGGVENYEK

int getRandomInt(int min, int max)
{
  return rand() % (max + 1 - min) + min;
}

int getRandomDouble(int max)
{
  return (float)rand() / max * 10;
}

// RENDEZESEK

void sortArray(char *array, int arraySize)
{
  for (int i = 0; i < arraySize - 1; ++i)
  {
    for (int j = 0; j < arraySize - i - 1; ++j)
    {
      // If current element is empty and next one is not empty, swap them
      if (array[j] == '\0' && array[j + 1] != '\0')
      {
        char temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
      // If both elements are non-empty and out of order, swap them
      else if (array[j] != '\0' && array[j + 1] != '\0' && array[j] > array[j + 1])
      {
        char temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void sortIntArray(int *array, int arraySize)
{
  for (int i = 0; i < arraySize - 1; ++i)
  {
    for (int j = 0; j < arraySize - i - 1; ++j)
    {
      // If current element is empty and next one is not empty, swap them
      if (array[j] == '\0' && array[j + 1] != '\0')
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
      // If both elements are non-empty and out of order, swap them
      else if (array[j] != '\0' && array[j + 1] != '\0' && array[j] > array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void sortDoubleArray(double *array, int arraySize)
{
  for (int i = 0; i < arraySize - 1; ++i)
  {
    for (int j = 0; j < arraySize - i - 1; ++j)
    {
      // If current element is empty and next one is not empty, swap them
      if (array[j] == '\0' && array[j + 1] != '\0')
      {
        double temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
      // If both elements are non-empty and out of order, swap them
      else if (array[j] != '\0' && array[j + 1] != '\0' && array[j] > array[j + 1])
      {
        double temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}